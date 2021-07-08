#include <WiFiManager.h>
#include <uri/UriRegex.h>

class WifiConfig
{
    private:
        WiFiManager m_wifiManager;                                          
        char const* SSIDProtail = "bateau";
        char const* motPasseAPortail = "BSC_3000";
        IPAddress* m_adresseIPPortail;
        IPAddress* m_passerellePortail;
        IPAddress* m_masqueReseauPortail;
        WebServer m_serveurWeb;
        char* m_addresseMqtt;

    public:
        WifiConfig();
        IPAddress* GetAddresseMQTT();
};