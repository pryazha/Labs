namespace UtilityLibraries;

public class DiapasonLibrary
{
    public DiapasonLibrary() {
    }

    public DiapasonLibrary(int minRange, int maxRange) {
    }

    ~DiapasonLibrary() {
    }

    public static bool InRange(int number, int minRange, int maxRange) {
        return number > minRange && number < maxRange;
    }

    private int minRange, maxRange;
}
