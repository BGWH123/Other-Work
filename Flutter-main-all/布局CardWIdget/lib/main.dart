import'package:flutter/material.dart';
void main()=>runApp(MyApp());


class MyApp extends StatelessWidget{
  @override
  Widget build(BuildContext context){
    var card=new Card(
      child: Column(
        children: <Widget>[
          ListTile(
              title:Text('重庆市南岸区',style: TextStyle(fontWeight:FontWeight.w500 ),),
            subtitle: Text('杨皓 193934821983'),
            leading:new Icon(Icons.account_box,color: Colors.lightBlue,)
          ),
          new Divider(),
          ListTile(
              title:Text('重庆市南岸区',style: TextStyle(fontWeight:FontWeight.w500 ),),
              subtitle: Text('杨皓 193934821983'),
              leading:new Icon(Icons.account_box,color: Colors.lightBlue,)
          ),
          new Divider(),
          ListTile(
              title:Text('重庆市南岸区',style: TextStyle(fontWeight:FontWeight.w500 ),),
              subtitle: Text('杨皓 193934821983'),
              leading:new Icon(Icons.account_box,color: Colors.lightBlue,)
          ),
        ],
      ),
    );
    return MaterialApp(
      title: 'Row Widget Demo',
      home: Scaffold(
        appBar: new AppBar(
          title: new Text('垂直方向布局'),
        ),
  body: Center(
child:card,
  ),
      ),
    );
  }
}