//By Stalker1917 (GNU/GPL)
//CHECK_FIELD and others by shengjuntu/onvif-ipcam



#include "soapH.h" 
#include "Nsmap\DeviceBinding.nsmap"     
#include <WinBase.h>
#include <string>
#define CHECK_FIELD(em,em2) \
if (em == NULL) {\
	size_t size = sizeof(*em);\
	em = new em2;\
	memset(em, 0, size);\
}\

#define NEW_FIELD(em1,em2,em3) \
em1 = new em2(em3);\

#define LOAD_FIELD(obj1, name1, obj2, name2) \
	(obj1).(name1) = (obj2).(name2);

#define STORE_FIELD(obj1, name1, obj2, name2) \
	 (obj2).(name2) = (obj1).(name1);

char *PortString = "8080";
char *Local = "127.0.0.1";
char *AdressString = "http://127.0.0.1:";


SOAP_FMAC5 int SOAP_FMAC6 __tds__GetSystemDateAndTime(struct soap*, struct _tds__GetSystemDateAndTime *tds__GetSystemDateAndTime, struct _tds__GetSystemDateAndTimeResponse *tds__GetSystemDateAndTimeResponse)
/** Web service operation '__tds__SetSystemFactoryDefault' implementation, should return SOAP_OK or error code */
{
	SYSTEMTIME tm;
	GetSystemTime(&tm);
	//tds__GetSystemDateAndTimeResponse = new _tds__GetSystemDateAndTimeResponse;
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime = new tt__SystemDateTime;
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->TimeZone = new tt__TimeZone;
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->TimeZone->TZ = "PST3PDT";
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->UTCDateTime = new tt__DateTime;
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->UTCDateTime->Date = new tt__Date;
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->UTCDateTime->Date->Year = tm.wYear;
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->UTCDateTime->Date->Month = tm.wMonth;
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->UTCDateTime->Date->Day = tm.wDay;
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->UTCDateTime->Time = new tt__Time;
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->UTCDateTime->Time->Hour = tm.wHour;
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->UTCDateTime->Time->Minute = tm.wMinute;
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->UTCDateTime->Time->Second = tm.wSecond;
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->LocalDateTime = new tt__DateTime;
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->LocalDateTime->Date = new tt__Date;
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->LocalDateTime->Time = new tt__Time;
	GetLocalTime(&tm);
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->LocalDateTime->Date->Year = tm.wYear;
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->LocalDateTime->Date->Month = tm.wMonth;
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->LocalDateTime->Date->Day = tm.wDay;
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->LocalDateTime->Time->Hour = tm.wHour;
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->LocalDateTime->Time->Minute = tm.wMinute;
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->LocalDateTime->Time->Second = tm.wSecond;
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->DaylightSavings = xsd__boolean__false_;
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->DateTimeType = tt__SetDateTimeType__Manual;
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->Extension = new tt__SystemDateTimeExtension;
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->Extension->__size = 0;
	tds__GetSystemDateAndTimeResponse->SystemDateAndTime->Extension->__any = 0;
	return SOAP_OK;
}
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetScopes(struct soap*, struct _tds__GetScopes *tds__GetScopes, struct _tds__GetScopesResponse *tds__GetScopesResponse)
	/** Web service operation '__tds__SetScopes' implementation, should return SOAP_OK or error code */
	{
	tds__GetScopesResponse->__sizeScopes = 1; 
	tds__GetScopesResponse->Scopes = new tt__Scope; //May be tt__Scope[2] etc...
	tds__GetScopesResponse->Scopes->ScopeDef = tt__ScopeDefinition__Fixed;
	tds__GetScopesResponse->Scopes->ScopeItem = "http://www.onvif.org/Profile/A";
	//= new tt__ScopeDefinition;
	 return SOAP_OK;
	}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetCapabilities(struct soap* soap, struct _tds__GetCapabilities *tds__GetCapabilities, struct _tds__GetCapabilitiesResponse *tds__GetCapabilitiesResponse)
/** Web service operation '__tds__SetDPAddresses' implementation, should return SOAP_OK or error code */
{
	char strbuf[255];
	//char strbuf2[255];
	char strbuf3[255];

	CHECK_FIELD(tds__GetCapabilitiesResponse->Capabilities, tt__Capabilities);
	CHECK_FIELD(tds__GetCapabilitiesResponse->Capabilities->Media, tt__MediaCapabilities)
	CHECK_FIELD(tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities, tt__RealTimeStreamingCapabilities)
	CHECK_FIELD(tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities->RTPMulticast, xsd__boolean)
	CHECK_FIELD(tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities->RTP_USCORETCP, xsd__boolean)
	CHECK_FIELD(tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities->RTP_USCORERTSP_USCORETCP, xsd__boolean)
	CHECK_FIELD(tds__GetCapabilitiesResponse->Capabilities->Extension, tt__CapabilitiesExtension)
	CHECK_FIELD(tds__GetCapabilitiesResponse->Capabilities->Extension->DeviceIO, tt__DeviceIOCapabilities)
	CHECK_FIELD(tds__GetCapabilitiesResponse->Capabilities->Device, tt__DeviceCapabilities)
	CHECK_FIELD(tds__GetCapabilitiesResponse->Capabilities->Device->System, tt__SystemCapabilities)
	CHECK_FIELD(tds__GetCapabilitiesResponse->Capabilities->Device->System->SupportedVersions, tt__OnvifVersion)

	//tds__GetCapabilitiesResponse->Capabilities = new tt__Capabilities;
	CHECK_FIELD(tds__GetCapabilitiesResponse->Capabilities->Analytics, tt__AnalyticsCapabilities)
	tds__GetCapabilitiesResponse->Capabilities->Analytics->AnalyticsModuleSupport = xsd__boolean__false_;
	tds__GetCapabilitiesResponse->Capabilities->Analytics->RuleSupport = xsd__boolean__false_;
	//tds__GetCapabilitiesResponse->Capabilities->Analytics->XAddr = "";
	//tds__GetCapabilitiesResponse->Capabilities->Device = new tt__DeviceCapabilities;
	strcpy(strbuf, AdressString);
	strcat(strbuf, PortString);
	//strcpy(strbuf2, "/onvif/device_service");
	//strbuf2 = "/onvif/device_service";
	strcpy(strbuf3, strbuf);
	strcat(strbuf3, "/onvif/device_service");
	tds__GetCapabilitiesResponse->Capabilities->Device->XAddr =new char[255];
	strcpy(tds__GetCapabilitiesResponse->Capabilities->Device->XAddr, strbuf3);
	 //= strbuf3;//"http://127.0.0.1:8080/onvif/device_service";//strbuf3;
	CHECK_FIELD(tds__GetCapabilitiesResponse->Capabilities->Device->Network, tt__NetworkCapabilities);
	NEW_FIELD(tds__GetCapabilitiesResponse->Capabilities->Device->Network->IPFilter, xsd__boolean, xsd__boolean__false_)
	NEW_FIELD(tds__GetCapabilitiesResponse->Capabilities->Device->Network->IPFilter, xsd__boolean, xsd__boolean__false_);
	NEW_FIELD(tds__GetCapabilitiesResponse->Capabilities->Device->Network->ZeroConfiguration, xsd__boolean, xsd__boolean__true_);
	NEW_FIELD(tds__GetCapabilitiesResponse->Capabilities->Device->Network->IPVersion6, xsd__boolean, xsd__boolean__false_);
	NEW_FIELD(tds__GetCapabilitiesResponse->Capabilities->Device->Network->DynDNS, xsd__boolean, xsd__boolean__true_);
	tds__GetCapabilitiesResponse->Capabilities->Extension->DeviceIO->VideoSources = TRUE;
	//strbuf2 = "/onvif/media_service";
	strcpy(strbuf3, strbuf);
	strcat(strbuf3, "/onvif/media_service");
	tds__GetCapabilitiesResponse->Capabilities->Media->XAddr = new char[255];
	strcpy(tds__GetCapabilitiesResponse->Capabilities->Media->XAddr, strbuf3); 
	//tds__GetCapabilitiesResponse->Capabilities->Media->XAddr = "http://127.0.0.1:8080/onvif/media_service";//strbuf3;
	NEW_FIELD(tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities->RTPMulticast, xsd__boolean, xsd__boolean__false_);
	NEW_FIELD(tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities->RTP_USCORETCP, xsd__boolean, xsd__boolean__true_);
	NEW_FIELD(tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities->RTP_USCORERTSP_USCORETCP, xsd__boolean, xsd__boolean__true_);
	tds__GetCapabilitiesResponse->Capabilities->Device->System->FirmwareUpgrade = xsd__boolean__true_;
	tds__GetCapabilitiesResponse->Capabilities->Device->System->__sizeSupportedVersions = 1; 
	tds__GetCapabilitiesResponse->Capabilities->Device->System->SupportedVersions->Major = 2;
	tds__GetCapabilitiesResponse->Capabilities->Device->System->SupportedVersions->Minor = 0;

	//*tds__GetCapabilitiesResponse->Capabilities->Device->Network->DiscoveryResolve = xsd__boolean__true_;
	//tds__GetCapabilitiesResponse->Capabilities->Events = new tt__EventCapabilities;
	//tds__GetCapabilitiesResponse->Capabilities->Imaging = new tt__ImagingCapabilities;
	//tds__GetCapabilitiesResponse->Capabilities->Media = new tt__MediaCapabilities;
	//tds__GetCapabilitiesResponse->Capabilities->PTZ = new tt__PTZCapabilities;
	//tds__GetCapabilitiesResponse->Capabilities->Extension = new tt__CapabilitiesExtension;
	return SOAP_OK;

}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDNS(struct soap*, struct _tds__GetDNS *tds__GetDNS, struct _tds__GetDNSResponse *tds__GetDNSResponse)
/** Web service operation '__tds__SetDNS' implementation, should return SOAP_OK or error code */
{
	
	CHECK_FIELD(tds__GetDNSResponse->DNSInformation, tt__DNSInformation)
	tds__GetDNSResponse->DNSInformation->FromDHCP = xsd__boolean__false_;
	tds__GetDNSResponse->DNSInformation->__sizeDNSManual = 1; 
	CHECK_FIELD(tds__GetDNSResponse->DNSInformation->DNSManual, tt__IPAddress)
	tds__GetDNSResponse->DNSInformation->DNSManual->Type = tt__IPType__IPv4;
	tds__GetDNSResponse->DNSInformation->DNSManual->IPv4Address = Local; //127.0....
	return SOAP_OK;

}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetNetworkInterfaces(struct soap*, struct _tds__GetNetworkInterfaces *tds__GetNetworkInterfaces, struct _tds__GetNetworkInterfacesResponse *tds__GetNetworkInterfacesResponse)
/** Web service operation '__tds__SetNetworkInterfaces' implementation, should return SOAP_OK or error code */
{
	tds__GetNetworkInterfacesResponse->__sizeNetworkInterfaces = 1;
	//tds__GetNetworkInterfacesResponse->NetworkInterfaces = new tt__NetworkInterface;
	CHECK_FIELD(tds__GetNetworkInterfacesResponse->NetworkInterfaces,tt__NetworkInterface)
	tds__GetNetworkInterfacesResponse->NetworkInterfaces->Enabled = xsd__boolean__true_;
	//tds__GetNetworkInterfacesResponse->NetworkInterfaces->Info = new tt__NetworkInterfaceInfo;
	CHECK_FIELD(tds__GetNetworkInterfacesResponse->NetworkInterfaces->Info, tt__NetworkInterfaceInfo)
	tds__GetNetworkInterfacesResponse->NetworkInterfaces->Info->HwAddress = "90:2B : 34 : A0 : 00 : 30"; 
	tds__GetNetworkInterfacesResponse->NetworkInterfaces->Info->MTU = new int(1500);
	//tds__GetNetworkInterfacesResponse->NetworkInterfaces->Info->Name = "";
	CHECK_FIELD(tds__GetNetworkInterfacesResponse->NetworkInterfaces->IPv4, tt__IPv4NetworkInterface)
	tds__GetNetworkInterfacesResponse->NetworkInterfaces->IPv4->Enabled = xsd__boolean__true_;
	CHECK_FIELD(tds__GetNetworkInterfacesResponse->NetworkInterfaces->IPv4->Config, tt__IPv4Configuration)
	tds__GetNetworkInterfacesResponse->NetworkInterfaces->IPv4->Config->DHCP = xsd__boolean__true_;
	CHECK_FIELD(tds__GetNetworkInterfacesResponse->NetworkInterfaces->IPv4->Config->FromDHCP, tt__PrefixedIPv4Address);
	tds__GetNetworkInterfacesResponse->NetworkInterfaces->IPv4->Config->FromDHCP->PrefixLength = 24;
	tds__GetNetworkInterfacesResponse->NetworkInterfaces->IPv4->Config->FromDHCP->Address = Local;//127.0....
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDeviceInformation(struct soap*, struct _tds__GetDeviceInformation *tds__GetDeviceInformation, struct _tds__GetDeviceInformationResponse *tds__GetDeviceInformationResponse)
/** Web service operation '__tds__SetSystemDateAndTime' implementation, should return SOAP_OK or error code */
{
	tds__GetDeviceInformationResponse->FirmwareVersion = "0.51";
	tds__GetDeviceInformationResponse->Model = "Detector";
	tds__GetDeviceInformationResponse->Manufacturer = "OOO";
	tds__GetDeviceInformationResponse->HardwareId = "1.0";
	tds__GetDeviceInformationResponse->SerialNumber = "123456";
	return SOAP_OK;
}