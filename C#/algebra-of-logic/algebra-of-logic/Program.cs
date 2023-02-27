using static System.Console;
using static System.Convert;

int numDim, n;
string vector_string;
string duplicate;
string substr;
int[] vector;
bool issuperech = true;


//fixing vector lines
do
{
    numDim = 0;
    WriteLine("Enter vector of values of a logical function through spacebar: ");
    vector_string = ReadLine();
    duplicate = string.Copy(vector_string);
    
    if ((vector_string.Contains('0') || vector_string.Contains('1')) && vector_string.Contains(' ') && vector_string.Length > 2)
        
        while (vector_string.Length > 0)
        {
            n = vector_string.LastIndexOf(' ');
            substr = vector_string.Substring(n + 1);
            
            if (substr != "1" && substr != "0") { numDim = 0; break; }
            else
            {
                numDim++; if (n < 0) break; vector_string = vector_string.Remove(n);
            }
        }
} while (numDim == 0 || checkLog2Digit(numDim) == -1);

vector = new int[numDim];

for (int i = 0; i < numDim; i++) vector[i] = duplicate[2 * i] - 48;
Write("Vector: (");

for (int i = 0; i < numDim; i++)
{
    if (i == numDim - 1) Write(vector[i]);
    else Write($"{vector[i]}, ");
}

Write(")\n");

if (vector[0] == 0) WriteLine("The function stores a constant 0.");
else WriteLine("The function does not store a constant 0.");

for (int i = 0, k = numDim - 1; i < numDim / 2; k--, i++)
    
    if (vector[i] != 0)
    {
        WriteLine("A function is not a contradiction.");
        issuperech = false;
        break;
    }

if (issuperech)
    WriteLine("A function is a contradiction.");

static int checkLog2Digit(int digit)
{
    if (digit % 2 == 1) return -1;
    
    digit /= 2;
    
    if (digit == 1) return 0;
    
    return checkLog2Digit(digit);
}