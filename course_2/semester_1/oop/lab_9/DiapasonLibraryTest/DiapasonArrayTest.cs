using DiapasonLibrary;

namespace DiapasonLibraryTest;

public class DiapasonArrayTest
{
    [Fact]
    public void DiapasonArray_Indexator_ReturnsValidInt()
    {
        // Arrange
        Diapason[] darr = new Diapason[4];
        darr[0] = new Diapason(1, 5);
        darr[1] = new Diapason(2, 6);
        darr[2] = new Diapason(3, 7);
        darr[3] = new Diapason(4, 8);

        DiapasonArray arr = new DiapasonArray(darr);

        // Act
        var result = arr[1];
        
        // Assert
        Assert.Equal(result, darr[1]);
    }
}
