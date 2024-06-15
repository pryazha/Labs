using Avalonia.Controls;
using Avalonia.Interactivity;
using lab_16.ViewModels;
using OrganizationsLibrary;

namespace lab_16.Views;

public partial class AddOrganizationDialog : Window
{
    public AddOrganizationDialog()
    {
        InitializeComponent();
    }

    private void OnAcceptClick(object sender, RoutedEventArgs args)
    {
        if (DataContext is AddOrganizationDialogViewModel viewModel)
        {
            if (viewModel.Name != null &&
                viewModel.Address != null &&
                viewModel.EmployeesCount > 0)
            {
                viewModel.Organization = new Organization(viewModel.Name,
                                                          viewModel.Address,
                                                          viewModel.EmployeesCount);
                Close();
            }
            else
            {
                viewModel.ErrorMessage = "All fields must be filled";
            }
        }
    }

    private void OnCancelClick(object sender, RoutedEventArgs args)
    {
        Close();
    }
}
