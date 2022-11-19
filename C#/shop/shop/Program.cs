using System;
using System.Collections.Generic;
using static System.Console;

namespace shop
{
    using System;
    using System.IO;

    class Collections
    {
        public int Number { get; set; }
        public string Series { get; set; }
        public override string ToString()
        {
            return $"event series: {Series} {Number}";
        }
    }

    class Generic : IComparable<Generic> // реалізує generic-інтерфейс 
    {
        public string First { get; set; }
        public string Last { get; set; }
        public DateTime Date { get; set; }
        public Collections StudentCard { get; set; }
        // порівнює за спрацюванням 
        public int CompareTo(Generic obj)
        {
            // жодних додаткових перевірок 
            return Last.CompareTo(obj.Last);
        }

        public override string ToString()
        {
            return $"\nLast event: {Last}; " +
                $"First event: {First}; " +
                $"Date of happening: {Date.ToShortDateString()}; " +
                $"{StudentCard.ToString()}";
        }
    }

    // порівнює за датою 
    class TimeComparer : IComparer<Generic> // реалізує generic-інтерфейс 
    {
        public int Compare(Generic x, Generic y)
        {
            // жодних додаткових перевірок 
            return DateTime.Compare(x.Date, y.Date);
        }
    }

    public class Cameras
    {
        public string Vendor { get; set; } // постачальник 
        public double Price { get; set; } // ціна 
        // перевизначення віртуального методу класу 
        public override string ToString()
        {
            return $"{Vendor} {Price}";
        }
    }
    public class Shop
    {
        // масив камер 
        Cameras[] cameraArr = new Cameras[] {
            new Cameras { Vendor = "\nSamsung", Price = 5200 },
            new Cameras { Vendor = "Asus", Price = 4700 },
            new Cameras { Vendor = "LG", Price = 4300 }
        };
        // властивість, яка повертає довжину масиву cameraArr  
        public int Length
        {
            get { return cameraArr.Length; }
        }
        //оголошення індексатора 
        public Cameras this[int index]
        {
            get
            {
                // перевіряємо коректність індексу масиву 
                if (index >= 0 && index < cameraArr.Length)
                {
                    return cameraArr[index];
                }
                // генерується виключення 
                throw new ArgumentOutOfRangeException(nameof(index),
                    $"Index {index} is out of range.");
            }
            set
            {
                cameraArr[index] = value;
            }
        }
        // перевантаження індексатора 
        public Cameras this[string vendor]
        {
            // індексатор містить лише get-аксесор 
            get
            {
                if (FindVendor(vendor) >= 0) // якщо постачальника знайдено 
                {
                    return this[FindVendor(vendor)];
                }
                // генерується виключення 
                throw new Exception($"No such vendor {vendor} in a list.");
            }
        }
        // пошук постачальника 
        private int FindVendor(string vendor)
        {
            for (int i = 0; i < cameraArr.Length; i++)
            {
                if (cameraArr[i].Vendor == vendor)
                {
                    return i; // постачальника знайдено 
                }
            }
            return -1; // постачальника не знайдено 
        }
    }

    public class RemoteControl
    {

        protected DateTime globalStartTime;
        public enum Status { OFF, ON };
        public int sensor { get; set; }
        const string path = "Recordings.txt";

        Status FireSystem;
        Status Lighting;
        bool PhotoCamera;

        Camera camera = new Camera();
        Valve valve = new Valve();

        //перевантаження інкременту
        //перевантаження інкременту для датчику руху, щоб одночасно працювало 2 датчики для більшого діапазону
        public static RemoteControl operator ++(RemoteControl s)
        {
            s.sensor++;
            return s;
        }

        public override string ToString()
        {
            return $"Sensor: x = {sensor}";
        }

        public void FireSystemON()
        {

            FireSystem = Status.ON;
            System.Console.WriteLine("\nThe Fire System is turned on\n");
            valve.SwitchOnDevice();
            RecordingToFile("\nThe Fire System is turned on\n");
        }

        public void FireSystemOFF()
        {
            FireSystem = Status.OFF;
            valve.SwitchOffDevice();
            System.Console.WriteLine("\nThe Fire System is turned off\n");
            RecordingToFile("\nThe Fire System is turned off\n");
        }

        public void SwichONLighting()
        {
            Lighting = Status.ON;
            System.Console.WriteLine("\nThe Lighting is turned on\n");
            RecordingToFile("\nThe Lighting is turned on\n");
        }

        public void SwichOFFLighting()
        {
            Lighting = Status.OFF;
            System.Console.WriteLine("\nThe Lighting is turned off\n");
            RecordingToFile("\nThe Lighting is turned off\n");
        }

        public void TakePhoto()
        {
            PhotoCamera = true;
            camera.SwitchOnDevice();
            Console.WriteLine("\nThe Photo is taken\n");
            camera.SwitchOffDevice();
            RecordingToFile("\nThe Photo is taken\n");
        }

        void RecordingToFile(string msg)
        {
            if (!File.Exists(path))
            {
                Console.Write("\nThe File is not found\n");
            }
            using (FileStream file = new FileStream(path, FileMode.Append))
            {
                using (StreamWriter stream = new StreamWriter(file))
                {
                    globalStartTime = DateTime.Now;
                    stream.WriteLine(msg + globalStartTime.ToLongTimeString());
                }
            }
        }
    }

    class BuidingFloor 
    { 
        int Height; 
        int Floor; 
    } 

    public abstract class Sensor
    {
        public enum Status { Passive, Active };
        public Status MainStatus;
        public RemoteControl Pult = new RemoteControl();
        public abstract void audit();
        public const int TLimit = 50;
        public Sensor()
        {
            MainStatus = Status.Passive;
        }
    }

    public sealed class Tempetature : Sensor
    {

        int tempetature;

        public Tempetature() : base()
        {
            tempetature = 0;
        }

        public Tempetature(int T) : base()
        {
            tempetature = T;
        }

        public override void audit()
        {
            if (tempetature > TLimit)
            {
                SwitchOnFireSystem();
            }
        }

        public void SwitchOnFireSystem()
        {

            if (MainStatus == Status.Passive)
            {
                Pult.FireSystemON();
                Pult.SwichONLighting();
                Pult.TakePhoto();
            }
            else
            {
                Console.WriteLine("\nThe FireSystem is already turned on \n");
            }
        }

        public void SwitchOffFireSystem()
        {

            MainStatus = Status.Passive;
            Pult.FireSystemOFF();
            Pult.SwichOFFLighting();

        }
    }

    public sealed class Move : Sensor
    {
        public override void audit()
        {

            if (MainStatus == Status.Active)
            {
                SwitchOnMoveSystem();
            }
        }

        public void SwitchOnMoveSystem()
        {
            MainStatus = Status.Active;
            Pult.SwichONLighting();
            Pult.TakePhoto();
            Console.WriteLine("\nThe Move Sencors is already recorded activity \n");
        }

        public void SwitchOffMoveSystem()
        {
            MainStatus = Status.Passive;
            Pult.SwichOFFLighting();
        }
    }

    public interface Device
    {
        abstract void SwitchOnDevice();
        abstract void SwitchOffDevice();
        abstract void CheckTheDeviceState();
    }

    class Camera : Device
    {

        static int WorkingHours = 0;

        public void SwitchOnDevice()
        {
            Console.WriteLine("\nThe Camera is switched on\n");
            WorkingHours++;
        }

        public void SwitchOffDevice()
        {
            Console.WriteLine("\nThe Camera is switched off\n");
        }

        public void CheckTheDeviceState()
        {

            if (WorkingHours > 100)
            {
                Console.WriteLine("\nThe Camera is broken\n");
            }
            else
            {
                Console.WriteLine("\nThe Camera working well!!!\n");
            }

        }
    }
    class Valve : Device
    {

        static int Сapacity = 0;

        public void SwitchOnDevice()
        {
            Console.WriteLine("\nThe Valve is opened\n");
            Сapacity += 10;
        }

        public void SwitchOffDevice()
        {
            Console.WriteLine("\nThe Valve is closed\n");
        }

        public void CheckTheDeviceState()
        {

            if (Сapacity > 100)
            {
                Console.WriteLine("\nThe Valve pour all water!!!\n");
            }

        }
    }

    class Apartment
    {

        protected static readonly DateTime globalStartTime;
        public int Number { get; set; }
        int Square { get; set; }
        bool statusPurchase = true;
        int AmoutOfWindows { get; set; }
        int AmoutOfDoors { get; set; }
        int TemperatureSensors { get; set; }
        int Valves { get; set; }
        protected int Cameras { get; set; }
        int MoveSensors { get; set; }

        public Tempetature SystemT = new Tempetature();
        public Move SystemM = new Move();

        void SetSensors()
        {
            TemperatureSensors = Square / 9;
            if (Square % 9 != 0)
            {
                TemperatureSensors++;
            }
        }

        void SetValves()
        {
            Valves = Square / 4;
            if (Square % 4 != 0)
            {
                Valves++;
            }
        }

        void SetCameras()
        {
            Cameras = Square / 16;
            if (Square % 16 != 0)
            {
                Cameras++;
            }
        }

        public void ShowSencors()
        {
            Console.WriteLine("\nCameras:" + Cameras +
                "\nValves:" + Valves +
                "\nTemperatureSensors:" + TemperatureSensors +
                "\nMoveSensors: " + MoveSensors);
        }

        public Apartment()
        {
            Number = 1;
            Square = 67;
            AmoutOfWindows = 7;
            AmoutOfDoors = 5;
            MoveSensors = AmoutOfDoors;
            SetCameras();
            SetSensors();
            SetValves();
        }

        public Apartment(int num, int sque, int windows, int doors)
        {
            System.Console.WriteLine("\nConstryctor with parameters\n");
            Number = num;
            Square = sque;
            AmoutOfWindows = windows;
            AmoutOfDoors = doors;
            SetCameras();
            SetSensors();
            SetValves();
            MoveSensors = doors;
        }

        public Apartment(Apartment A)
        {
            AmoutOfDoors = A.AmoutOfDoors;
            Square = A.Square;
            AmoutOfWindows = A.AmoutOfWindows;
            Number = A.Number;
            TemperatureSensors = A.TemperatureSensors;
            Valves = A.Valves;
            Cameras = A.Cameras;
            MoveSensors = A.MoveSensors;
            Console.Write("\nThe Object copied\n");
        }

        static Apartment()
        {
            globalStartTime = DateTime.Now;
            Console.WriteLine("Static constructor sets global start time to {0}",
                globalStartTime.ToLongTimeString());
        }

        public void EnterParameters()
        {
            Console.Write("\nEnter number of the Apartment: ");
            Number = Convert.ToInt32(Console.ReadLine());
            Console.Write("\nEnter Square of the Apartment: ");
            Square = Convert.ToInt32(Console.ReadLine());
            Console.Write("\nEnter how much windows in the Apartment: ");
            AmoutOfWindows = Convert.ToInt32(Console.ReadLine());
            Console.Write("\nEnter how much doors in the Apartment: ");
            AmoutOfDoors = Convert.ToInt32(Console.ReadLine());
            SetCameras();
            SetSensors();
            SetValves();
            MoveSensors = AmoutOfDoors;
            statusPurchase = true;
        }

        public void ShowInfo()
        {

            if (statusPurchase)
            {
                Console.Write("\nThe Number of the Apartment:{0}\n " +
                   "\nSquare of the Apartment:{1}\n" +
                   "\nAmount of windows in the Apartment:{2}\n" +
                    "\nAmount of doors in the Apartment:{3}\n"
                   , Number, Square, AmoutOfWindows, AmoutOfDoors);
            }
            else
            {
                Console.Write("\nThe Apartment is sold\n");
            }
        }

        public void WriteOBJToFile(string file1)
        {

            if (!File.Exists(file1))
            {
                Console.Write("\nThe File is not found\n");
            }
            using (FileStream file = new FileStream(file1, FileMode.OpenOrCreate))
            {
                using (StreamWriter stream = new StreamWriter(file))
                {
                    stream.WriteLine(Number);
                    stream.WriteLine(AmoutOfWindows);
                    stream.WriteLine(AmoutOfDoors);
                    stream.WriteLine(Square);
                }
            }
        }

        public void ReadFile(string file1)
        {

            if (!File.Exists(file1))
            {
                Console.Write("\nThe File is not found\n");
                return;
            }

            using (StreamReader file = new StreamReader(file1))
            {
                Number = Convert.ToInt32(file.ReadLine());
                AmoutOfWindows = Convert.ToInt32(file.ReadLine());
                AmoutOfDoors = Convert.ToInt32(file.ReadLine());
                Square = Convert.ToInt32(file.ReadLine());
            }

        }

        public override string ToString()
        {
            return ("\nThe Number of the Apartment:" + Number
                + "\nSquare of the Apartment:" + Square +
                "\nAmount of windows in the Apartment:" + AmoutOfWindows +
                 "\nAmount of doors in the Apartment:" + AmoutOfDoors);
        }

        public void SellApartment()
        {
            statusPurchase = false;
            Console.Write("\nThe Apartment is sold\n");
        }
    }

    class Program
    {

        static void Main()
        {

            string file1 = "FlatInfo.txt"; 
            string file2 = "test.txt"; 

            Apartment Flat = new Apartment(); 
            Flat.ShowInfo(); 
            Flat.WriteOBJToFile(file1); 

            Apartment Flat1 = new Apartment(); 
            Flat1.ReadFile(file2); 
            Flat1.ShowInfo(); 

            Apartment Flat2 = new Apartment(5, 120, 10, 6); 
            Console.WriteLine(Flat2.ToString()); 
            Flat2.ShowSencors(); 
            Flat2.SellApartment(); 
            Flat2.ShowInfo(); 

            Apartment Flat3 = new Apartment(); 
            Flat3.EnterParameters(); 
            Flat3.ShowInfo();
            Flat3.SystemT.SwitchOnFireSystem(); 
            System.Threading.Thread.Sleep(2000); 
            Flat3.SystemT.SwitchOffFireSystem(); 

            Apartment Flat4 = new Apartment(Flat3); 
            Flat4.ShowInfo(); 
            Flat4.SystemM.SwitchOnMoveSystem(); 
            Flat4.SystemM.SwitchOffMoveSystem(); 

            List<Generic> group = new List<Generic> // створюємо generic-колекцію 
            {
                new Generic
                {
                    First = "Camera",
                    Last = "Light",
                    Date = new DateTime(2022, 3, 12),
                    StudentCard = new Collections { Number = 189356, Series = "E1" }
                },
                new Generic
                {
                    First = "Valve",
                    Last = "Sensor",
                    Date = new DateTime(2022, 4, 22),
                    StudentCard = new Collections { Number = 345185, Series = "E2" }
                },
                new Generic
                {
                    First = "Fire system",
                    Last = "Lightning",
                    Date = new DateTime(2022, 11, 30),
                    StudentCard = new Collections { Number = 258322, Series = "E3" }
                },
                new Generic
                {
                    First = "Taking photo",
                    Last = "Switch off the light",
                    Date = new DateTime(2022, 5, 10),
                    StudentCard = new Collections { Number = 513484, Series = "E4" }
                }
            };
            Console.WriteLine("\n======== List of events ========\n");
            foreach (Generic student in group)
            {
                Console.WriteLine(student);
            }

            // виводимо список подій, відсортований за останньою подією  
            Console.WriteLine("\n======== List sorted by last name  ========\n");
            group.Sort();
            foreach (Generic student in group)
            {
                Console.WriteLine(student);
            }

            // виводимо список подій, відсортований за часом спрацювання  
            Console.WriteLine("\n======== List sorted by time ========\n");
            group.Sort(new TimeComparer());
            foreach (Generic student in group)
            {
                Console.WriteLine(student);
            }

            Console.WriteLine("\n===================================\n");

            Shop cameras = new Shop();
            // використовуємо set аксесор індексатора this[int index] 
            cameras[2].Price += 100;
            try
            {
                // використовуємо get аксесор індексатора this[int index] 
                for (int i = 0; i < cameras.Length; i++)
                {
                    Console.WriteLine(cameras[i]);
                }
            }
            // обробка виключення 
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }
            // використовуємо get аксесор індексатора this[string vendor] 
            Console.WriteLine($"Vendor Asus: {cameras["Asus"]}.");
            try
            {
                Console.WriteLine($"Vendor HP: {cameras["HP"]}.");
            }
            // обробка виключення 
            catch (Exception ex)
            {
                Console.WriteLine($"Not supported input: {ex.Message}");
            }

        }
    }
}