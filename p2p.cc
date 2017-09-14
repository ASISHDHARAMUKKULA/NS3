#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/application-module.h"
using namespace ns3;
NS_LOG_COMPONENT_DEFINE("FirstScriptexample");
int main(int argc,char *argv[])
{
	LogComponentEnable("UdpEchoClientApplication",LOG_LEVEL_INFO);
	LogComponentEnable("updateEchoServerApplication",LOG_LEVEL_INFO);
	NodesContainer nodes;
	nodes.Create(2);
	PointToPointHelper PointToPoint;
	PointToPoint.setDeviceAttribute("DataRate",StringValue("5Mbps"));
	PointToPoint.SetChannelAttribute("Delay",StringValue("2ms"));
	NetDeviceContainer devices;
	devices=PointToPoint.Install(nodes);
	internetStackHelper stack;
	stack.Install(nodes);
	Ipv4AddressHelper address;
	address.Setbase("10.1.1.0","255.255.255.0");
	Ipv4InterfaceContainer interfaces = address.Assign (devices);
	UdpEchoServerhelper echoserver (9);
	ApplicationContainer serverApps=echoServer.Install (nodes.Get(1));
	serverApps.Start (seconds (1.0));
	serverapps.Stop (Seconds (10.0));
	UdpEchoClientHelper echoClient (interfaces.GetAddress (1),9);
	echoClient.SetAttribute ("MaxPackets",uintegerValue (5));
	echoClient.SetAttribute ("Interval",TimeValue (Seconds (1.0));
	echoClient.SetAttribute ("PacketSize",UintegerValue (1024));
	ApplicationContainer clientApps = echoClient.Install (nodes.Get (0));
	ClientApps.Start (Seconds (2.0));
	ClientApps.Stop (Seconds (10.0));
	Simulator::Run();
	Simulator::Destroy();
	return 0;
}
