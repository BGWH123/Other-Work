import 'package:flutter/material.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: MyHomePage(title: 'Flutter Demo Home Page'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  MyHomePage({Key?key,required this.title}) : super(key: key);

  final String title;

  @override
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  int _counter = 0;
  double _height=10;
  double _width=10;
  double _size=10;

  void _incrementCounter() {
    setState(() {
      _counter++;
      _height+=30;
      _width+=30;
      _size+=5;

      if(_height>=400){
        _counter=0;
        _width=30;
        _height=30;
        _size=3;
      }
    });
  }

  @override
  Widget build(BuildContext context) {

    return Scaffold(
      appBar: AppBar(
        title: Text(widget.title),
      ),
      body:Center(
      child:AnimatedContainer(
        duration: Duration(milliseconds: 500),
        width: _width,
        height: _height,
     //   color: Colors.lightGreen,

        child: Center(
        child:Text(
        '$_counter',
    style: TextStyle(fontSize: _size),
    )
        ),

        decoration: BoxDecoration(
          gradient: LinearGradient(
            colors: [Colors.greenAccent,Colors.lightBlue],
          ),
          boxShadow: [BoxShadow(spreadRadius: 25,blurRadius: 25)],
          borderRadius :BorderRadius.circular(20),
        ),


      ),
    ),
      floatingActionButton: FloatingActionButton(
        onPressed: _incrementCounter,
        tooltip: 'Increment',
        child: Icon(Icons.add),
      ), // This trailing comma makes auto-formatting nicer for build methods.
    );
  }
}
