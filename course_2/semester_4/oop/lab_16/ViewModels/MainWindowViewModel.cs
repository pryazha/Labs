using System;
using System.IO;
using System.Text.Json;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Threading;
using System.Threading.Tasks;
using System.Collections.Generic;
using System.Xml.Serialization;
using OrganizationsLibrary;
using MyCollection;
using Avalonia.Controls;
using Avalonia.Controls.ApplicationLifetimes;
using Avalonia.Platform.Storage;
using Avalonia.Threading;
using Avalonia;
using System.Text;
using MainProgram;
using System.Runtime.Serialization.Formatters.Binary;

namespace lab_16.ViewModels;

public class MainWindowViewModel : INotifyPropertyChanged
{
    private MyGenericHashtable<Organization> _hst;
    private ObservableCollection<MyGenericElement<Organization>> _hashtableItems;
    public ObservableCollection<MyGenericElement<Organization>> HashtableItems
    {
        get => _hashtableItems;
        set
        {
            _hashtableItems = value;
            OnPropertyChanged(nameof(HashtableItems));
        }
    }

    private string _orgName;
    public string OrgName
    {
        get => _orgName;
        set
        {
            _orgName = value;
            OnPropertyChanged(nameof(OrgName));
        }
    }

    private List<string> _fileTypes;
    public List<string> FileTypes
    {
        get => _fileTypes;
        set => _fileTypes = value;
    }

    private string _selectedType;
    public string SelectedType
    {
        get => _selectedType;
        set
        {
            _selectedType = value;
            OnPropertyChanged(nameof(SelectedType));
        }
    }

    public event PropertyChangedEventHandler? PropertyChanged;

    protected virtual void OnPropertyChanged(string propertyName)
    {
        PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
    }

    public MainWindowViewModel()
    {
        _hst = new MyGenericHashtable<Organization>(10);
        _hashtableItems = new ObservableCollection<MyGenericElement<Organization>>(_hst);
        _orgName = "";
        _fileTypes = new List<string> { ".json", ".xml", ".dat", ".txt" };
        _selectedType = _fileTypes[0];
    }

    public void FillHashtableCommand()
    {
        FillHashtable(_hst, 10);
        RefreshHashtableItems();
    }

    public async void AddNewOrgCommand()
    {
        var dialog = new Views.AddOrganizationDialog();
        var dialogViewModel = new AddOrganizationDialogViewModel();
        dialog.DataContext = dialogViewModel;
        var mainWindow = Application.Current?.ApplicationLifetime is
            IClassicDesktopStyleApplicationLifetime desktop ? desktop.MainWindow : null;
        if (mainWindow != null)
        {
            await dialog.ShowDialog(mainWindow);
            
            if (dialogViewModel != null && dialogViewModel.Organization != null)
            {
                _hst.Add(dialogViewModel.Organization);
                RefreshHashtableItems();
            }
        }
    }

    public void RemoveAllOrgsCommand()
    {
        foreach (var item in _hst)
            _hst.Remove(item);
        RefreshHashtableItems();
    }
    
    public void FindOrgCommand()
    {
        if (!String.IsNullOrEmpty(OrgName))
        {
            var result = _hst[OrgName];
            if (result != null)
                Console.WriteLine(result);
        }
    }

    public void RemoveOrgCommand()
    {
        if (!String.IsNullOrEmpty(OrgName))
        {
            _hst.Remove(OrgName);
            RefreshHashtableItems();
        }
    }

    public void ShowOrgsCommand()
    {
        RefreshHashtableItems();
    }

    public void SortOrgsCommand()
    {
        var result = _hst.SortOrgsBy(org => org.EmployeesCount);
        HashtableItems.Clear();
        foreach (var item in result)
            HashtableItems.Add(item);
    }

    public void SelectOrgsCommand()
    {
        var result = _hst.SelectWhere(elem => elem.Name.Contains('8'));
        HashtableItems.Clear();
        foreach (var item in result)
            HashtableItems.Add(item);
    }

    public void SelectOrgsWithEmplCommand()
    {
        var result = _hst.SelectWhere(elem => elem.EmployeesCount > 100);
        HashtableItems.Clear();
        foreach (var item in result)
            HashtableItems.Add(item);
    }

    public async Task SaveToFile(TopLevel topLevel)
    {
        var file = await topLevel.StorageProvider.SaveFilePickerAsync(new FilePickerSaveOptions
        {
            Title = $"Save {_selectedType} File",
            SuggestedFileName = $"{_selectedType}",
            FileTypeChoices = new List<FilePickerFileType>
            {
                new($"{_selectedType} Files") { Patterns = new[] { $"*{_selectedType}" } }
            }
        });

        if (file != null)
        {
            try
            {
                await using var stream = await file.OpenWriteAsync();
                switch (_selectedType)
                {
                    case ".txt": {
                        MyGenericElement<Organization>[]? buckets = new MyGenericElement<Organization>[_hst.Count];
                        string bucketsString = "";
                        foreach (var item in _hst)
                            bucketsString += item.ToString() + "\n";
                        var streamWriter = new StreamWriter(stream);
                        await streamWriter.WriteAsync(bucketsString);
                    } break;
                    case ".json":
                        await JsonSerializer.SerializeAsync(stream, _hst);
                        break;
                    case ".xml": {
                        MyGenericElement<Organization>[]? buckets = new MyGenericElement<Organization>[_hst.Count];
                        int i = 0;
                        foreach (var item in _hst)
                            buckets[i++] = item;
                        var xmlSerializer = new XmlSerializer(typeof(MyGenericElement<Organization>[]));
                        xmlSerializer.Serialize(stream, buckets);
                    } break;
                    case ".dat": {
                        MyGenericElement<Organization>[]? buckets = new MyGenericElement<Organization>[_hst.Count];
                        int i = 0;
                        foreach (var item in _hst)
                            buckets[i++] = item;
                        var binaryFormatter = new BinaryFormatter();
                        binaryFormatter.Serialize(stream, buckets);
                    } break;
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error during serialization: {ex.Message}");
            }
        }
    }

    public async Task LoadFromFile(TopLevel topLevel)
    {
        var files = await topLevel.StorageProvider.OpenFilePickerAsync(new FilePickerOpenOptions
        {
            Title = $"Open {_selectedType} File",
            AllowMultiple = false,
            FileTypeFilter = new List<FilePickerFileType>
            {
                new($"{_selectedType} Files") { Patterns = new[] { $"*{_selectedType}" } }
            }
        });

        if (files.Count >= 1)
        {
            try
            {
                await using var stream = await files[0].OpenReadAsync();
                MyGenericElement<Organization>[]? newHst = null;
                switch (_selectedType)
                {
                    case ".json":
                        newHst = await JsonSerializer.DeserializeAsync<MyGenericElement<Organization>[]>(stream);
                        break;
                    case ".xml":
                        var xmlSerializer = new XmlSerializer(typeof(MyGenericElement<Organization>[]));
                        newHst = (MyGenericElement<Organization>[]?)xmlSerializer.Deserialize(stream);
                        break;
                    case ".dat":
                        var binaryFormatter = new BinaryFormatter();
                        newHst = (MyGenericElement<Organization>[]?)binaryFormatter.Deserialize(stream);
                        break;
                }

                if (newHst != null)
                {
                    _hst = new MyGenericHashtable<Organization>(10); 
                    foreach (var item in newHst)
                        _hst.Add(item);
                    RefreshHashtableItems();
                }
                else
                {
                    Console.WriteLine("Deserialization resulted in null object.");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error during deserialization: {ex.Message}");
            }
        }
    }

    private void RefreshHashtableItems()
    {
        HashtableItems.Clear();
        foreach (var item in _hst)
            HashtableItems.Add(item);
    }

    private static void FillHashtable(MyGenericHashtable<Organization> hs, int size)
    {
        for (int i = 0; i < size; i++)
        {
            var rnd = new Random();
            int item = rnd.Next(1, 6);
            switch (item)
            {
                case 1:
                    hs.Add(new Organization());
                    break;
                case 2:
                    hs.Add(new InsuranceCompany());
                    break;
                case 3:
                    hs.Add(new ShipbuildingCompany());
                    break;
                case 4:
                    hs.Add(new Factory());
                    break;
                case 5:
                    hs.Add(new Library());
                    break;
            }
        }
    }
}
