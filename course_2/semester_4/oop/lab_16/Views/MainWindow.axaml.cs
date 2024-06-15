using Avalonia.Controls;
using Avalonia.Interactivity;
using lab_16.ViewModels;

namespace lab_16.Views;

public partial class MainWindow : Window
{
    public MainWindow()
    {
        InitializeComponent();
    }

    private async void SaveFileButton_Clicked(object sender, RoutedEventArgs args)
    {
        var topLevel = GetTopLevel(this);

        if (DataContext is MainWindowViewModel viewModel && topLevel != null)
        {
            await viewModel.SaveToFile(topLevel);
        }
    }

    private async void OpenFileButton_Clicked(object sender, RoutedEventArgs args)
    {
        var topLevel = GetTopLevel(this);

        if (DataContext is MainWindowViewModel viewModel && topLevel != null)
        {
            await viewModel.LoadFromFile(topLevel);
        }
    }
}
