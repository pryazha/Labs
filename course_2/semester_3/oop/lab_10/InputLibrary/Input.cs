namespace InputLibrary;

public class Input
{
    public static int IntInput(string message)
    {
        int number;
        bool isConvert;
        do
        {
            Console.Write(message);
            isConvert = int.TryParse(Console.ReadLine(), out number);
            if (!isConvert)
            {
                Console.WriteLine("Неверный формат данных");
            }
        } while (!isConvert);
        return number;
    }

    public static string StringInput(string message)
    {
        string result;
        do 
        {
            Console.Write(message);
            result = Console.ReadLine() ?? "";
            if (result == "")
            {
                Console.WriteLine("Строка не может быть пустой");
            }
        } while (result == "");
        return result;
    }
}
