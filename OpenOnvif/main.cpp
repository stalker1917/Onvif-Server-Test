/* GNU GPL Onvif Server based on song2010040402102/SOAP_Server_Client 
by Stalker1917*/

#include "soapH.h" 
//#include "DeviceBinding.nsmap"     
//#include <WinBase.h>

int main(int argc,char *argv[])
{
	int m,s;
	struct soap add_soap;

	soap_init(&add_soap);

	soap_set_namespaces(&add_soap,namespaces);
	
	m = soap_bind(&add_soap, NULL, 8080, 100);
	//m= soap_bind(&add_soap,NULL,123, 100); 

	if(m < 0) 
	{
		soap_print_fault(&add_soap,stderr);
		exit(-1);
	}
	printf("Socketconnection successful: master socket = %d\n",m);

	while(1) 
	{
		s = soap_accept(&add_soap);

		if (s < 0) 
		{
			soap_print_fault(&add_soap,stderr);
			exit(-1);
		}
		printf("Socket connection successful: slave socket =%d\n",s);

		soap_serve(&add_soap);         

		soap_end(&add_soap);
	}

	return 0;
}



