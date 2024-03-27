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
            var originalElem = originalHst[i];
            var copyElem = copyHst[i];

            if (originalElem != null &&
                copyElem != null)
            {
                if (!copyHst.Contains(i) ||
                    !(String.Compare(originalElem.ToString(), copyElem.ToString()) == 0))
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

    [Fact]
    public void GetIndexer_ReturnsDefaultTValueWhenKeyIsNull()
    {
        // Arrange
        var hst = new MyGenericHashtable<int?, Organization>(1); 

        // Act
        var result = hst[null];

        // Assert
        Assert.Null(result);
    }

    [Fact]
    public void GetIndexer_ReturnsDefaultTValueWhenThereIsNoSuchKey()
    {
        // Arrange
        var hst = new MyGenericHashtable<int?, Organization>(1); 

        // Act
        var result = hst[1];

        // Assert
        Assert.Null(result);
    }

    [Fact]
    public void GetIndexer_ReturnsExpectedValue()
    {
        // Arrange
        var hst = new MyGenericHashtable<int, Organization>(1); 
        var expected = new Organization();
        hst.Add(1, expected);

        // Act
        var result = hst[1];

        // Assert
        Assert.Equal(expected, result);
    }

    [Fact]
    public void GetIndexer_ReturnsExpectedValueWhenThereAreTwoChainedElements()
    {
        // Arrange
        var hst = new MyGenericHashtable<int, Organization>(1);
        var expected = new Organization();

        // Act
        hst.Add(1, new Organization());
        hst.Add(2, expected);
        var result = hst[2];

        // Assert
        Assert.Equal(expected, result);
    }

    [Fact]
    public void GetIndexer_ReturnsNullWhenThereAreTwoChainedElementsAndNoSuchKey()
    {
        // Arrange
        var hst = new MyGenericHashtable<int, Organization>(1);

        // Act
        hst.Add(1, new Organization());
        hst.Add(2, new Organization());
        var result = hst[0];

        // Assert
        Assert.Null(result);
    }

    [Fact]
    public void SetIndexer_ReturnsExpectedValue()
    {
        // Arrange
        var hst = new MyGenericHashtable<int, Organization>(1);
        var expected = new Organization();

        // Act
        hst.Add(1, new Organization());
        hst[1] = expected;
        var result = hst[1];

        // Assert
        Assert.Equal(expected, result);
    }

    [Fact]
    public void SetIndexer_ReturnsExpectedValueWhenKeyIsNull()
    {
        // Arrange
        var hst = new MyGenericHashtable<int?, Organization>(1);
        var expected = new Organization();

        // Act
        hst.Add(1, expected);
        hst[null] = new Organization();
        var result = hst[1];

        // Assert
        Assert.Equal(expected, result);
    }

    [Fact]
    public void SetIndexer_ReturnsExpectedValueWhenKeyIsNotExist()
    {
        // Arrange
        var hst = new MyGenericHashtable<int, Organization>(1);
        var expected = new Organization();

        // Act
        hst.Add(1, expected);
        hst[2] = new Organization();
        var result = hst[1];

        // Assert
        Assert.Equal(expected, result);
    }

    [Fact]
    public void Add_ReturnsNothingWhenElemIsNull()
    {
        // Arrange
        var hst = new MyGenericHashtable<int, Organization>(1);

        // Act
        hst.Add(null);

        // Assert
        Assert.Empty(hst);
    }

    [Fact]
    public void Add_ReturnsExpectedValue()
    {
        // Arrange
        var hst = new MyGenericHashtable<int, Organization>(1);
        var expectedOrg = new Organization();
        var expected = new MyGenericElement<int, Organization>(1, expectedOrg);

        // Act
        hst.Add(expected);
        var result = hst[1];

        // Assert
        Assert.Equal(expectedOrg, result);
    }

    [Fact]
    public void Add_ReturnsFalseWhenKeyIsNull()
    {
        // Arrange
        var hst = new MyGenericHashtable<int?, Organization>(1);

        // Act
        var result = hst.Add(null, new Organization());

        // Assert
        Assert.False(result);
    }

    [Fact]
    public void Clear_SuccessfullClear()
    {
        // Arrange
        var hst = new MyGenericHashtable<int, Organization>(1);

        // Act
        hst.Add(1, new Organization());
        hst.Clear();

        // Assert
        Assert.Empty(hst);
    }

    [Fact]
    public void Contains_ReturnFalseWhenItemIsNull()
    {
        // Arrange
        var hst = new MyGenericHashtable<int, Organization>(1);

        // Act
        var result = hst.Contains(null);

        // Assert
        Assert.False(result);
    }

    [Fact]
    public void Contains_ReturnFalseWhenBucketsIsNull()
    {
        // Arrange
        var hst = new MyGenericHashtable<int, Organization>();
        var item = new MyGenericElement<int, Organization>(1, new Organization());

        // Act
        var result = hst.Contains(item);

        // Assert
        Assert.False(result);
    }

    [Fact]
    public void Contains_ReturnTrueWhenItemIsFound()
    {
        // Arrange
        var hst = new MyGenericHashtable<int, Organization>(1);
        var expected = new MyGenericElement<int, Organization>(1, new Organization());

        // Act
        hst.Add(expected);
        var result = hst.Contains(expected);

        // Assert
        Assert.True(result);
    }

    [Fact]
    public void Contains_ReturnTrueWhenItemIsFoundWithChainedElements()
    {
        // Arrange
        var hst = new MyGenericHashtable<int, Organization>(1);
        var expected = new MyGenericElement<int, Organization>(2, new Organization());

        // Act
        hst.Add(1, new Organization());
        hst.Add(expected);
        var result = hst.Contains(expected);

        // Assert
        Assert.True(result);
    }

    [Fact]
    public void Contains_ReturnFalseWhenHashtableIsEmpty()
    {
        // Arrange
        var hst = new MyGenericHashtable<int, Organization>(1);
        var expected = new MyGenericElement<int, Organization>(1, new Organization());

        // Act
        var result = hst.Contains(expected);

        // Assert
        Assert.False(result);
    }

    [Fact]
    public void Contains_ReturnFalseWhenThereAreChainedElementsAndNoSuchItem()
    {
        // Arrange
        var hst = new MyGenericHashtable<int, Organization>(1);
        var expected = new MyGenericElement<int, Organization>(3, new Organization());

        // Act
        hst.Add(1, new Organization());
        hst.Add(2, new Organization());
        var result = hst.Contains(expected);

        // Assert
        Assert.False(result);
    }

    [Fact]
    public void Contains_ReturnFalseWhenKeyIsNull()
    {
        // Arrange
        var hst = new MyGenericHashtable<int, Organization>(1);

        // Act
        hst.Add(1, new Organization());
        var result = hst.Contains(null);

        // Assert
        Assert.False(result);
    }

    [Fact]
    public void Remove_ReturnsFalseWhenItemIsNull()
    {
        // Arrange
        var hst = new MyGenericHashtable<int, Organization>(1);
        MyGenericElement<int, Organization>? item = null;

        // Act
        var result = hst.Remove(item);

        // Assert
        Assert.False(result);
    }

    [Fact]
    public void Remove_ReturnsTrueWhenItemIsRemove()
    {
        // Arrange
        var hst = new MyGenericHashtable<int, Organization>(1);
        var item = new MyGenericElement<int, Organization>(1, new Organization());

        // Act
        hst.Add(item);
        var result = hst.Remove(item);

        // Assert
        Assert.True(result);
        Assert.Empty(hst);
    }
}
