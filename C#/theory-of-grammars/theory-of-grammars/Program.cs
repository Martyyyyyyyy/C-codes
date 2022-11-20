using static System.Console;

string str;
WriteLine("Введіть символьний ланцюжок: ");

do
{
    str = ReadLine();
}
while (str == null);

bool isgood = false;

if (str.Contains(' ')) goto PrintMsg;

int commaIndex, startBraceIndex, endBraceIndex;

do
{
    commaIndex = str.IndexOf(',');
    
    if (commaIndex < 0) commaIndex = str.Length;
    
    if (str.Contains('[') && str[commaIndex - 1] == ']')
    {
        if (str[0] == '[') goto PrintMsg;
        
        startBraceIndex = str.IndexOf('[');
        endBraceIndex = commaIndex - 1;
        
        for (int i = 0; i < startBraceIndex; i++) 
            if (!Char.IsLetter(str[i])) goto PrintMsg;
       
        for (int i = startBraceIndex + 1; i < endBraceIndex; i++)
            if (!Char.IsDigit(str[i])) goto PrintMsg;
    }
    else for (int i = 0; i < commaIndex; i++)
            if (!Char.IsLetter(str[i])) goto PrintMsg;
    
    if (commaIndex != str.Length)
        str = str.Substring(commaIndex + 1);
} while (commaIndex != str.Length);

isgood = true;
PrintMsg:

if (!isgood)
    WriteLine("Даний ланцюжок не генерується заданою граматикою.");
else WriteLine("Даний ланцюжок генерується заданою граматикою.");
