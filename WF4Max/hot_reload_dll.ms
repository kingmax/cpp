filename = @"D:\git\cpp\WF4Max\bin\Release\WF4Max.dll"

assembly = (dotNetClass "System.IO.File").ReadAllBytes(filename)
asm = (dotNetClass "System.Reflection.Assembly").Load(assembly)

w = dotNetObject "WF4Max.MyWindow"
show w
showMethods w

fn btnBox_click sender e = 
(
	box()
)

dotNet.addEventHandler w.btnBox "click" btnBox_click
dotNet.setLifetimeControl w.btnBox #dotnet

w.show()
--w.showDialog()
w.Parent

windows.addChild (windows.getMaxHWND()) w.Handle