package org.credil.helloworldservice;

import org.credil.helloworldservice.R;
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
        bindService(new Intent("org.credil.helloworldservice.HelloWorldServiceInterface"),
                serviceConnection, Context.BIND_AUTO_CREATE);
        */

        IBinder helloworld = ServiceManager.getService("org.credil.helloworldservice.HelloWorldServiceInterface");
        if (helloworld == null) {
            Log.e(LOG_TAG, "hello service not found ");
            return;
        }


        /** if you already have a stub e.g. AIDL that works **/
        HelloWorldServiceInterface interf = HelloWorldServiceInterface.Stub.asInterface(helloworld);
        try {
            interf.hellothere("Using interfaces");
        } catch (RemoteException re) {
            Log.w(LOG_TAG, "Error calling the interface:" + re.getMessage(), re);
        }

        /** If you want to "hack around"                                 **/
        Log.e(LOG_TAG, "hello " + helloworld.toString());
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        int _result;
        try {
            _data.writeInterfaceToken("org.credil.helloworldservice.HelloWorldServiceInterface");
            _data.writeString("Calling from Java now");
            Log.d(LOG_TAG, "Data:" + _data.toString());
            helloworld.transact((android.os.IBinder.FIRST_CALL_TRANSACTION + 0), _data, _reply, 0);
            _reply.readException();
            _result = _reply.readInt();
        } catch (RemoteException re) {
            Log.w(LOG_TAG, "Remote exception");
        } finally {
            _reply.recycle();
            _data.recycle();
        }

    }
}