using MyCollection;
using OrganizationsLibrary;

namespace Tests;

public class MyGenericElementTests
{
    [Fact]
    public void GetHashCode_ReturnsExpectedHashCode()
    {
        // Arrange
        var element = new MyGenericElement<int, string>(42, "Hello");

        // Act
        var hashCode = element.GetHashCode();

        // Assert
        Assert.Equal(42.GetHashCode(), hashCode);
    }

    [Fact]
    public void GetHashCode_ReturnsNegativeOneWhenKeyIsNull()
    {
        // Arrange
        var element = new MyGenericElement<int?, string>(null, "Hello");

        // Act
        var hashCode = element.GetHashCode();

        // Assert
        Assert.Equal(-1, hashCode);
    }

    [Theory]
    [InlineData(1, "One", "Ключ: 1\nЗначение: One")]
    [InlineData(null, "NullValue", "Ключ:\nЗначение:")]
    [InlineData(1, null, "Ключ:\nЗначение:")]
    public void ToString_ReturnsExpectedStringRepresentation(
        int? key, string? value, string expected)
    {
        // Arrange
        var element = new MyGenericElement<int?, string?>(key, value);

        // Act
        var result = element.ToString();

        // Assert
        Assert.Equal(expected, result);
    }
}

public class MyGenericHashtableTests
{
    [Theory]
    [InlineData(0)]
    [InlineData(1)]
    [InlineData(100)]
    public void CustomConstructor_ReturnsExpectedCapacity(int expected)
    {
        // Arrange
        var hst = new MyGenericHashtable<int, Organization>(expected);

        // Act

        // Assert
        Assert.Equal(expected, hst.Capacity);
    }

    [Fact]
    public void DefaultConstructor_ReturnZeroCount()
    {
        // Arrange
        var hst = new MyGenericHashtable<int, Organization>();

        // Act
        var resultCount = hst.Count;

        // Assert
        Assert.Equal(0, resultCount);
    }

    [Fact]
    public void CustomContructor_ReturnsExpectedCount()
    {
        // Arrange
        int expectedCount = 2;
        var hst = new MyGenericHashtable<int, Organization>(1);

        // Act
        hst.Add(1, new Organization());
        hst.Add(2, new Organization());
        int resultCount = hst.Count;

        // Assert
        Assert.Equal(expectedCount, resultCount);
    }

    [Fact]
    public void CopyConstructor_ReturnsValidHst()
    {
        // Arrange
        int expectedCapacity = 2;
        int expectedCount = 2;
        var originalHst = new MyGenericHashtable<int, Organization>(expectedCapacity); 
        originalHst.Add(1, new Organization());
        originalHst.Add(2, new Organization());
        var copyHst = new MyGenericHashtable<int, Organization>(originalHst);

        // Act

        int resultCapacity = copyHst.Capacity;
        int resultCount = copyHst.Count;
        bool isEqual = true;
        for (int i = 1; i <= 2; ++i)
        {
            if (originalHst[i] != null &&
                copyHst[i] != null)
            {
                if (!copyHst.Contains(i) ||
                    !(String.Compare(copyHst[i].ToString(), originalHst[i].ToString()) == 0))
                {
                    isEqual = false;
                }
            }
        }

        // Assert
        Assert.True(isEqual);
        Assert.Equal(expectedCapacity, resultCapacity);
        Assert.Equal(expectedCount, resultCount);
    }
}
