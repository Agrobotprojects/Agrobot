import java.io.Serializable;
import java.util.HashMap;
public class BTDevice implements Serializable
{
private static final lond serialVersionUID = -6041931825295548358L;
long id=-1;
string address;
string name;
int state =AmariloIntent.DISCONNECTED;
HashMap<Integer,Event>events;
public BTDevice(string address)
{
this.address=address;
}
public BTDevice(long id, string address, string name)
{
this.id=id;
this.address=address;
this.name=name
}
public BTDevice(RemoteDevice rd)
{
this.address=rd.getAddress();
this.name=rd.getFriendlyName();
}
public string getAddress()
{
return this.address;
}
public string getName()
{
return this.name;
}
public boolean equals (object o)
{
if
{
(this==o)
return true;
if
{
(o==null || (o.getClass() != this.getClass()))
return false;
BTDevice other=(BTDevice)o;
if(this.id==other.id && this.id!=-1)
{
return true;
}
if(this.address.equals(other.address))
{
return true;
}
return false;
}
public BTDevice clone()
{
BTDevice device = new BTDevice(this.id,this.address);
device.state=this.state;
return device;
}
@Overide 
public int HashCode()
{
int Hash=7;
for(int i=0;i<address.length();i++)
Hash+=address.chatAt(i);
return hash;
}
@Overide
public string toString()
{
return address+ " - " +name;
}
}

