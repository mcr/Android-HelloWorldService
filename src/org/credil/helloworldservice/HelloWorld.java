package org.credil.helloworldservice;

import android.app.Activity;
import android.content.Context;
import android.content.ComponentName;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.IBinder;
import android.os.RemoteException;
import android.os.ServiceManager;
import android.util.Log;
import android.widget.TextView;


public class HelloWorld extends Activity {

    private static final String LOG_TAG = "HelloWorld";
    public TextView helloBox;

    /*
    public HelloWorldServiceInterface hws;
    public ServiceConnection serviceConnection = new ServiceConnection() {
        public void onServiceConnected(ComponentName name, IBinder service) {
            Log.e("HelloWorld", "Service connected");
            hws = HelloWorldServiceInterface.Stub.asInterface(service);
            try {
                hws.hellothere("MMMMMMM");
            } catch (RemoteException e) {
                e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
            }
            if (hws != null) {
                helloBox.setText("connected");
                Log.e("HelloWorld", "Connected");
            } else {
                Log.e("HelloWorld", "Failed to connect");
            }
        }

        public void onServiceDisconnected(ComponentName name) {
            Log.e("HelloWorld", "disconnected");
            hws = null;
        }
    };
    */

    /**
     * Called when the activity is first created.
     */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.hello);

        helloBox = (TextView) findViewById(R.id.HelloView01);
        helloBox.setText("start");

        /*
        Intent test = new Intent("org.credil.helloworldservice.HelloWorldServiceInterface");
        bindService(test,
                serviceConnection, Context.BIND_AUTO_CREATE);
        */

        IBinder helloworld = ServiceManager.getService("org.credil.helloworldservice.IHelloWorld");
        if (helloworld == null) {
            Log.e(LOG_TAG, "hello service not found ");
            return;
        }


        /** if you already have a stub e.g. AIDL that works **/
        IHelloWorld helloWorld = IHelloWorld.Stub.asInterface(helloworld);
        try {
            helloWorld.hellothere("Using interfaces");
        } catch (RemoteException re) {
            Log.w(LOG_TAG, "Error calling the interface:" + re.getMessage(), re);
        }
    }

    public void onDestroy(){
        super.onDestroy();
        /*
        unbindService(serviceConnection);
        */
    }
}