using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;
using TCD.Arduino.Bluetooth;
using Windows.Foundation;
using Windows.Networking.Proximity;
using Windows.UI.Popups;
using Windows.UI.Xaml;

namespace RCCarHomeBrew
{
    public class RCCar_ViewModel : INotifyPropertyChanged
    {
        #region Variables
        private String _connectionStatus;

        private BluetoothConnectionManager bcm = new BluetoothConnectionManager();

        public event PropertyChangedEventHandler PropertyChanged;

        #endregion

        #region properties

        public  BluetoothConnectionManager BluetoothManager { get {  return bcm; } }        

        public String ConnectionStatus
        {
            get { return _connectionStatus; }
            set { _connectionStatus = value; OnPropertyChanged("ConnectinoStatus"); }
        }

        public int SelectedConnectionIndex { get; set; }

        #endregion

        public RCCar_ViewModel()
        {
            this.ConnectionStatus = "Not Connected";          
            BluetoothManager.ExceptionOccured += BluetoothManager_ExceptionOccured;
        }
        
        private async void BluetoothManager_ExceptionOccured(object sender, Exception ex)
        {
            var md = new MessageDialog(ex.Message, "We've got a problem with bluetooth...");
            md.Commands.Add(new UICommand("Ah.. thanks.."));
            md.DefaultCommandIndex = 0;
            var result = await md.ShowAsync();
        }        

        public void MoveBackward()
        {
            BluetoothManager.SendMessageAsync(1);
        }
        public void MoveForward()
        {
            BluetoothManager.SendMessageAsync(2);

        }        
        public void TurnRight()
        {
            BluetoothManager.SendMessageAsync(3);
        }
        public void TurnLeft()
        {
            BluetoothManager.SendMessageAsync(4);
        }

        public void StopAll()
        {
            BluetoothManager.SendMessageAsync(5);
        }

        public void ExecuteConnection()
        {
            if (SelectedConnectionIndex == 0)
            {
                BluetoothManager.EnumerateDevicesAsync(new Rect(0,0,200,200));
                ConnectionStatus = "Connected";
            }
            else
            {
                BluetoothManager.Disconnect();
            }
        }

        public void OnPropertyChanged(String prop)
        {
            PropertyChangedEventHandler handler = PropertyChanged;

            if (handler != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(prop));
            }
        }

    }



}
