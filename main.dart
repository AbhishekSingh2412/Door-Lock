// For performing some operations asynchronously
import 'dart:async';
import 'dart:convert';

// For using PlatformException
import 'package:flutter/services.dart';

import 'package:flutter/material.dart';
import 'package:flutter_bluetooth_serial/flutter_bluetooth_serial.dart';
import 'package:flutter_bluetooth/Functionality.dart';
import 'Bottom.dart';
void main() => runApp(MyApp());


/// This is the main application widget.
class MyApp extends StatelessWidget {
  static const String _title = 'Home Safety App';

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: _title,
      home: Scaffold(
        appBar: AppBar(title: const Text(_title)),
        body: MyStatefulWidget(),
      ),
    );
  }
}


class MyStatefulWidget extends StatefulWidget {
  MyStatefulWidget({Key key}) : super(key: key);

  @override
  _MyStatefulWidgetState createState() => _MyStatefulWidgetState();
}
class _MyStatefulWidgetState extends State<MyStatefulWidget> {
  final _formKey = GlobalKey<FormState>();
  bool pass_checked=false;
  @override
  Widget build(BuildContext context) {
    return Form(
      key: _formKey,
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: <Widget>[
          TextFormField(
            decoration: const InputDecoration(
              hintText: 'Enter password',
            ),
            validator: (value) {
              if (value.isEmpty) {
                return 'Please enter some text';
                }
              if(value=="109400"){
                pass_checked=true;
              }
              return null;
            },
          ),
          Padding(
            padding: const EdgeInsets.symmetric(vertical: 16.0),
            child: Center(
              child:BottomButton(buttonTitle: 'PROCEED',onTap: (){

              Navigator.push(context, MaterialPageRoute(builder:(context){
                return BluetoothApp();
                },
                ),
                );
                },),


            ),
          ),
        ],
      ),
    );
  }
}




