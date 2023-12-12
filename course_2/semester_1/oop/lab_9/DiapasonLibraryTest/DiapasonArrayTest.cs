using DiapasonLibrary;

namespace DiapasonLibraryTest;

public class DiapasonArrayTest
{
    [Theory]
    [InlineData(0)]
    [InlineData(5)]
    public void DiapasonArray_LengthProperty_ReturnsValidLength(int size)
    {
        // Arrange
        DiapasonArray arr = new DiapasonArray(size);

        // Act
        var result = arr.Length;

        // Assert
        Assert.Equal(size, result);
    }

    [Fact]
    public void DiapasonArray_ConstructorWithoutParam_ReturnsEmptyArr()
    {
        // Arrange
        DiapasonArray arr = new DiapasonArray();

        // Act
        var result = arr.Length;

        // Assert
        Assert.Equal(0, result);
    }

    [Fact]
    public void DiapasonArray_ConstructorWithSize_ReturnsInvalidSize()
    {
        // Arrange
        DiapasonArray arr = new DiapasonArray(-1);

        // Act
        var result = arr.Length;

        // Assert
        Assert.Equal(0, result);
    }

    [Theory]
    [InlineData(1)]
    [InlineData(10)]
    public void DiapasonArray_ConstructorWithSize_ReturnsValidArr(int size)
    {
        // Arrange
        DiapasonArray arr = new DiapasonArray(size);

        // Act
        var result = arr.Length;

        // Assert
        Assert.Equal(size, result);
    }

    [Fact]
    public void DiapasonArray_IndexatorGet_ReturnsError()
    {
        // Arrange
        Diapason[] darr = new Diapason[2];
        darr[0] = new Diapason(1, 5);
        darr[1] = new Diapason(2, 6);

        DiapasonArray arr = new DiapasonArray(darr);

        Diapason expected = new Diapason();

        // Act
        var result = arr[2];
        
        // Assert
        Assert.Equal(expected, result);
    }

    [Fact]
    public void DiapasonArray_IndexatorGet_ReturnsValidInt()
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

    [Fact]
    public void DiapasonArray_IndexatorSet_ReturnsError()
    {
        // Arrange
        Diapason[] darr = new Diapason[2];
        darr[0] = new Diapason(1, 5);
        darr[1] = new Diapason(2, 6);

        DiapasonArray arr = new DiapasonArray(darr);

        Diapason diap = new Diapason(3, 6);

        // Act
        arr[2] = diap;
        
        // Assert
        for (int i = 0; i < arr.Length; i++)
        {
            Assert.Equal(darr[i], arr[i]);
        }
    }

    [Fact]
    public void DiapasonArray_IndexatorSet_ReturnsValidSet()
    {
        // Arrange
        Diapason[] darr = new Diapason[2];
        darr[0] = new Diapason(1, 5);
        darr[1] = new Diapason(2, 6);

        DiapasonArray arr = new DiapasonArray(darr);

        Diapason diap = new Diapason(3, 6);

        // Act
        arr[1] = diap;
        
        // Assert
        Assert.Equal(diap, arr[1]);
    }
}
