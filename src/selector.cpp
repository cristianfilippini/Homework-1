#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

ros::Publisher selector_pub;

std::vector<std::string> split(const std::string& str, const std::string& delimitatore)
{
	std::vector<std::string> campi_split;
	std::string::size_type posizione=0;
	std::string::size_type precedente=0;
	
	while ((posizione=str.find(delimitatore, precedente))!=std::string::npos)
	{
		campi_split.push_back(str.substr(precedente, posizione-precedente));
		precedente=posizione+1;
	}
	campi_split.push_back(str.substr(precedente));
	
	return campi_split;
	

}


void chatterCallback(const std_msgs::String::ConstPtr& msg)
{	
	std::string s=msg->data.c_str();
	std_msgs::String msgNew;
	
	std::stringstream ss;

	std::cout << "\nScegli quale parte del messaggio estrarre (n-Nome; e-Età; c-Corso di studi; a-Messaggio intero): ";
	char c;
	std::cin >> c;
	
	switch(c)
	{
		case 'n':
			
    		ss << split(s,":").at(0);
    		msgNew.data = ss.str();	
    		selector_pub.publish(msgNew);
			break;
			
		case 'e':
			ss << split(s,":").at(1);;
    		msgNew.data = ss.str();
    		selector_pub.publish(msgNew);
   			break;
   		
   		case 'c':
			ss << split(s,":").at(2);;
    		msgNew.data = ss.str();
    		selector_pub.publish(msgNew);
   			break;
		
		case 'a':
			selector_pub.publish(msg);
    		break;
    	}
	
	
}



	
	
int main(int argc, char **argv)
{	
	ros::init(argc, argv, "selector");
	ros::NodeHandle n;
	
	ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
	selector_pub = n.advertise<std_msgs::String>("selector", 1000);
	
	
	ros::spin();	
	return 0;
}
