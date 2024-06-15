using System;
using System.ComponentModel;
using System.Collections.ObjectModel;
using System.Threading;
using System.Threading.Tasks;

namespace SortingVisualization.ViewModels;

public class MainWindowViewModel : INotifyPropertyChanged
{
    public int[] SourceArray { get; }

    public ObservableCollection<int> AscendingArr { get; }
    public ObservableCollection<int> DescendingArr { get; }

    private bool _sortingIsDone;
    public bool SortingIsDone
    {
        get => _sortingIsDone;
        set
        {
            _sortingIsDone = value;
            OnPropertyChanged(nameof(SortingIsDone));
        }
    }

    private bool _sortingInProgress;
    public bool SortingInProgress
    {
        get => _sortingInProgress;
        set
        {
            _sortingInProgress = value;
            OnPropertyChanged(nameof(SortingInProgress));
        }
    }

    public event PropertyChangedEventHandler? PropertyChanged;

    protected virtual void OnPropertyChanged(string propertyName)
    {
        PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
    }

    public MainWindowViewModel()
    {
        _sortingIsDone = false;
        _sortingInProgress = false;
        _random = new Random();
        AscendingArr = new ObservableCollection<int>();
        DescendingArr = new ObservableCollection<int>();
        SourceArray = new int[10];
        for (int i = 0; i < 10; ++i)
        {
            int value = _random.Next(0, 20);
            AscendingArr.Add(value);
            DescendingArr.Add(value);
            SourceArray[i] = value;
        }
    }

    public async void StartSortingCommand()
    {
        SortingInProgress = true;
        SortingIsDone = false;

        await Task.WhenAll(AscendingSort(), DescendingSort());

        SortingIsDone = true;
        SortingInProgress = false;
    }

    private async Task AscendingSort()
    {
        for (int i = 0; i < AscendingArr.Count; ++i)
        {
            for (int j = i + 1; j < AscendingArr.Count; ++j)
            {
                if (AscendingArr[i] > AscendingArr[j])
                {
                    await Task.Delay(1000);
                    int temp = AscendingArr[i];
                    AscendingArr[i] = AscendingArr[j];
                    AscendingArr[j] = temp;
                }
            }
        }
    }

    private async Task DescendingSort()
    {
        for (int i = 0; i < DescendingArr.Count; ++i)
        {
            for (int j = i + 1; j < DescendingArr.Count; ++j)
            {
                if (DescendingArr[i] < DescendingArr[j])
                {
                    await Task.Delay(1000);
                    int temp = DescendingArr[i];
                    DescendingArr[i] = DescendingArr[j];
                    DescendingArr[j] = temp;
                }
            }
        }
    }

    private Random _random;
}
