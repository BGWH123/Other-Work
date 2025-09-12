import'package:flutter/material.dart';
void main()=>runApp(MyApp());


class MyApp extends StatelessWidget{
  @override
  Widget build(BuildContext context){
   var stack=new Stack(
     alignment: const FractionalOffset(0.5, 0.8),
     children: <Widget>[
       new CircleAvatar(
         backgroundImage:new NetworkImage('https://img-prod-cms-rt-microsoft-com.akamaized.net/cms/api/am/imageFileData/RE4Gswv?ver=6d0d') ,
         radius: 100.0,
       ),
     new Positioned(
       top: 10.0,
       left: 50.0,
       child: new Text('杨浩杨皓'),
     ),
       new Positioned(
         bottom: 10.0,
         right: 10.0,
         child: new Text('卢佳卢佳'),
       ),
     ],
   );
    return MaterialApp(
      title: 'Row Widget Demo',
      home: Scaffold(
        appBar: new AppBar(
          title: new Text('垂直方向布局'),
        ),
  body: Center(
child: stack,
  ),
      ),
    );
  }
}