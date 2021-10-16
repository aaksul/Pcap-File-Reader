#include<iterator_source.h>
#include<source.h>
#include<iostream>
#include<ip_header.h>


PcapFile_It::PcapFile_It(Pcap_File* source,pcap_t* fp):source{source},fp{fp},count{0}
{
    
}


ip_header* PcapFile_It::Get_Next_Packet_Info()
{
    count++;
    struct ip_header* my_ip{new ip_header()};
    pcap_pkthdr* head;
    const u_char* data;
    
    pcap_next_ex(fp,&head,&data);
    for (size_t i = 0; i < 4; i++)
    {
        my_ip->SOURCE_IP_ADRESS[i]=static_cast<int>(data[i+26]);
    }
    
    for (size_t i = 0; i < 4; i++)
    {
        my_ip->DEST_IP_ADRESS[i]=static_cast<int>(data[i+30]);
    }
    
    return my_ip;
    
}