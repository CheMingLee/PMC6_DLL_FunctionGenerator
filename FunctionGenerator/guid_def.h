
// include initguid.h as described in Visual C++ under Knowledge base topic:
// HOWTO: Avoid Error LNK2001 Unresolved External Using DEFINE_GUID
#include "INITGUID.H"

//
// Define an Interface Guid for genport device class.
// This GUID is used to register (IoRegisterDeviceInterface)
// an instance of an interface so that user application
// can control the genport device.
//

// {C9D23E7E-9EE5-4d86-8260-F51CD5B28854}
//DEFINE_GUID(DRIVER_GUID, 
//0xc9d23e7e, 0x9ee5, 0x4d86, 0x82, 0x60, 0xf5, 0x1c, 0xd5, 0xb2, 0x88, 0x54);


#ifdef PMC6_USE_USB
//PMC6 USB
// {18B0A857-C688-45e6-B4B2-8C4265956C45}
DEFINE_GUID(DRIVER_GUID, 
0x18b0a857, 0xc688, 0x45e6, 0xb4, 0xb2, 0x8c, 0x42, 0x65, 0x95, 0x6c, 0x45);
#else
//PMC6 PCIe
// {F1BD739B-6BBB-496b-9252-F61EE1A0A58E}
DEFINE_GUID(DRIVER_GUID, 
0xf1bd739b, 0x6bbb, 0x496b, 0x92, 0x52, 0xf6, 0x1e, 0xe1, 0xa0, 0xa5, 0x8e);
#endif