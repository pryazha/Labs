using OrganizationsLibrary;

namespace OrganizationsLibraryTests;

public class LibraryTests
{
    [Fact]
    public void Library_SetterNegativeBooksCount_ReturnsZero()
    {
        // Arrange
        var library = new Library();
        library.BooksCount = -1;

        // Act
        int result = library.BooksCount;

        // Assert
        Assert.Equal(0, result);
    }

    [Fact]
    public void Library_ShallowCopy_ReturnsEqualButNotSameInstance()
    {
        // Arrange
        var library1 = new Library();
        library1.manager = new Manager("ManagerName");

        // Act
        var library2 = library1.ShallowCopy();

        // Assert
        Assert.Equal(library1, library2);
        Assert.Equal(library1.BooksCount, library2.BooksCount);
        Assert.NotSame(library1, library2);
        Assert.Same(library1.manager, library2.manager);
    }

    [Fact]
    public void Library_Clone_ReturnsEqualButNotSameInstanceWithClonedManager()
    {
        // Arrange
        var library1 = new Library("FactoryName", "FactoryAddress", 100, 100);
        library1.manager = new Manager("ManagerName");

        // Act
        var library2 = (Library)library1.Clone();

        // Assert
        Assert.Equal(library1, library2);
        Assert.NotSame(library1, library2);
        Assert.Equal(library1.BooksCount, library2.BooksCount);
        Assert.Equal(library1.manager.Name, library2.manager.Name);
        Assert.NotSame(library1.manager, library2.manager);
    }
}
