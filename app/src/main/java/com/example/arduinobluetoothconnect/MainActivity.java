package com.example.arduinobluetoothconnect;

import androidx.appcompat.app.AppCompatActivity;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.os.Bundle;

import java.io.IOException;
import java.util.UUID;

public class MainActivity extends AppCompatActivity {

    static final UUID UUID = java.util.UUID.fromString("00001101-0000-1000-8000-00805F9B34FB"); // This UUID works!!!

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        turnBlueToothOn();
        BluetoothAdapter btAdapter = BluetoothAdapter.getDefaultAdapter();
        System.out.println(btAdapter.getBondedDevices());

        BluetoothDevice HC05 = btAdapter.getRemoteDevice("00:20:10:08:50:E1");
        System.out.println(HC05.getName());
        BluetoothSocket btSocket = null;
        do {
            try {
                btSocket = HC05.createInsecureRfcommSocketToServiceRecord(UUID);
                System.out.println(btSocket);
                btSocket.connect();
                System.out.println(btSocket.isConnected());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }while (!btSocket.isConnected());

        try {
            btSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    private void turnBlueToothOn(){

        try {
            BluetoothAdapter bluetooth = BluetoothAdapter.getDefaultAdapter();
            if(!bluetooth.isEnabled()){
                bluetooth.enable();
            }
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

}