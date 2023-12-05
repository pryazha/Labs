using DiapasonLibrary;

namespace DiapasonLibraryTest;

public class DiapasonTest
{
    [Theory]
    [InlineData(3.3, 1.4, 5)]
    [InlineData(0, -1.4, 0.4)]
    [InlineData(5, 1.4, 5)]
    public void Diapason_InRange_ReturnsTrue(double num, double x, double y)
    {
        // Arrange
        Diapason diap = new Diapason(x, y);
        
        // Act
        var result = diap.InRange(num);

        // Assert
        Assert.True(result);
    }

    [Theory]
    [InlineData(0, 1.4, 5)]
    [InlineData(6, 1.4, 5)]
    public void Diapason_InRange_ReturnsFalse(double num, double x, double y)
    {
        // Arrange
        Diapason diap = new Diapason(x, y);
        
        // Act
        var result = diap.InRange(num);

        // Assert
        Assert.False(result);
    }

    [Theory]
    [InlineData(1.4, 1.4, 5)]
    [InlineData(0, -1.4, 0.4)]
    [InlineData(5, 1.4, 5)]
    public void Diapason_s_InRange_ReturnsTrue(double num, double x, double y)
    {
        // Arrange
        
        // Act
        var result = Diapason.InRange(num, x, y);

        // Assert
        Assert.True(result);
    }

    [Theory]
    [InlineData(0, 1.4, 5)]
    [InlineData(6, 1.4, 5)]
    public void Diapason_s_InRange_ReturnsFalse(double num, double x, double y)
    {
        // Arrange
        
        // Act
        var result = Diapason.InRange(num, x, y);

        // Assert
        Assert.False(result);
    }

    [Theory]
    [InlineData(4, 1, 5)]
    [InlineData(4.5, 0.5, 5)]
    public void Diapason_OperatorExlamationPoint_ReturnsValidLength(double expected, double x, double y)
    {
        // Arrange
        Diapason diap = new Diapason(x, y);

        // Act
        var result = !diap;

        // Assert
        Assert.Equal(expected, result);
    }

    [Theory]
    [InlineData(1, 4, 2, 5)]
    [InlineData(-0.5, 4.5, 0.5, 5.5)]
    public void Diapason_OperatorPlusPlus_ReturnsValidDiap(double x, double y, double exp_x, double exp_y)
    {
        // Arrange
        Diapason diap = new Diapason(x, y);

        // Act
        ++diap;

        // Assert
        Assert.Equal(exp_x, diap.x);
        Assert.Equal(exp_y, diap.y);
    }

    [Fact]
    public void Diapason_ExplicitIntCasting_ReturnsValidInt()
    {
        // Arrange
        Diapason diap = new Diapason(3.1, 5.5);

        // Act
        int result = (int)diap;

        // Assert
        Assert.Equal(3, result);
    }

    [Fact]
    public void Diapason_ImplicitDoubleCasting_ReturnsValidDouble()
    {
        // Arrange
        Diapason diap = new Diapason(3.2, 5.5);

        // Act
        double result = diap;

        // Assert
        Assert.Equal(5.5, result);
    }
    
    [Fact]
    public void Diapason_OperatorSumWithNum_ReturnsValidNum()
    {
        // Arrange
        Diapason diap = new Diapason(1.5, 5.3);
        double num = 5;
        Diapason expected = new Diapason(1.5 + num, 5.3 + num);

        // Act
        var result = diap + num;

        // Assert
        Assert.Equal(expected, result);
    }

    [Theory]
    [InlineData(1, 5, 1)]
    [InlineData(1, 5, 3)]
    [InlineData(1, 5, 5)]
    public void Diapason_OperatorGreaterThan_ReturnsTrue(double x, double y, double num)
    {
        // Arrange
        Diapason diap = new Diapason(x, y);

        // Act
        var result = num < diap;

        // Assert
        Assert.True(result);
    }

    [Theory]
    [InlineData(1, 5, 0)]
    [InlineData(1, 5, 6)]
    public void Diapason_OperatorGreaterThan_ReturnsFalse(double x, double y, double num)
    {
        // Arrange
        Diapason diap = new Diapason(x, y);

        // Act
        var result = num < diap;

        // Assert
        Assert.False(result);
    }
}
