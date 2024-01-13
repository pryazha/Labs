using OrganizationsLibrary;

namespace OrganizationsLibraryTests;

public class NotHierarchicalClassTests
{
    [Fact]
    public void PositiveNumberSetter_ReturnsZeroWhenValueIsNegative()
    {
        // Arrange
        var num = new NotHierarchicalClass();

        // Act
        num.PositiveNumber = -1;
        int result = num.PositiveNumber;

        // Assert
        Assert.Equal(0, result);
    }
}
