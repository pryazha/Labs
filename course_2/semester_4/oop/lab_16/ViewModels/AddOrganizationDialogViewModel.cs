using System;
using System.Collections.ObjectModel;
using System.ComponentModel;
using OrganizationsLibrary;
using MyCollection;

namespace lab_16.ViewModels;

public class AddOrganizationDialogViewModel : INotifyPropertyChanged
{
    private string? _name;
    private string? _address;
    private string _errorMessage;
    private int _employeesCount;

    public string? Name
    {
        get => _name;
        set
        {
            _name = value;
            OnPropertyChanged(nameof(Name));
        }
    }

    public string? Address
    {
        get => _address;
        set
        {
            _address = value;
            OnPropertyChanged(nameof(Address));
        }
    }

    public string ErrorMessage
    {
        get => _errorMessage;
        set
        {
            _errorMessage = value;
            OnPropertyChanged(nameof(ErrorMessage));
        }
    }

    public int EmployeesCount
    {
        get => _employeesCount;
        set
        {
            _employeesCount = value;
            OnPropertyChanged(nameof(EmployeesCount));
        }
    }

    public Organization? Organization { get; set; }

    public event PropertyChangedEventHandler? PropertyChanged;

    public AddOrganizationDialogViewModel()
    {
        _errorMessage = "";
    }

    protected virtual void OnPropertyChanged(string propertyName)
    {
        PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
    }
}
