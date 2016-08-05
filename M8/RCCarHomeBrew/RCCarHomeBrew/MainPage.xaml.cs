using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.Graphics.Display;
using Windows.Phone.UI.Input;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

namespace RCCarHomeBrew
{
    public sealed partial class MainPage : Page
    {
        RCCar_ViewModel _dataContext { get; set; }

        public MainPage()
        {
            this.InitializeComponent();
            this.Loaded += MainPage_Loaded;
        }

        private void MainPage_Loaded(object sender, RoutedEventArgs e)
        {
            this.DataContext = new RCCar_ViewModel();
            this._dataContext = this.DataContext as RCCar_ViewModel;
        }

        private void ExecuteButton_Click(object sender, RoutedEventArgs e)
        {
            _dataContext.ExecuteConnection();
        }

        private void Canvas_PointerMoved(object sender, PointerRoutedEventArgs e)
        {
            //Debug.WriteLine(e.GetCurrentPoint(sender as Canvas).Position);
            Point touchPoint = e.GetCurrentPoint(sender as Canvas).Position;

            double x = touchPoint.X;
            double y = touchPoint.Y;

            if((x>35 && x < 350) && (y > 10 && y < 94))
            {
                _dataContext.MoveForward();
            }
            else if ((x > 37.5 && x < 350) && (y > 384.5 && y < 475.5))
            {
                _dataContext.MoveBackward();
            }
            else if ((x > 14 && x < 160) && (y > 126.5 && y < 335.5))
            {
                _dataContext.TurnLeft();
            }
            else if ((x > 244.5 && x < 378.5) && (y > 126 && y < 337))
            {
                _dataContext.TurnRight();
            }
            else
            {
                _dataContext.StopAll();
            }
        }

        private void Canvas_PointerReleased(object sender, PointerRoutedEventArgs e)
        {
            _dataContext.StopAll();
        }
    }
}
