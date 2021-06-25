#include <WiFiManager.h>
#include <uri/UriRegex.h>

class WifiConfig
{
    private:
        WiFiManager m_wifiManager;                                          
        char const* SSIDProtail = "bateau";
        char const* motPasseAPortail = "Bonjour01";
        IPAddress* m_adresseIPPortail;
        IPAddress* m_passerellePortail;
        IPAddress* m_masqueReseauPortail;
        WiFiManagerParameter* m_parametrePersonalise;
        WebServer m_serveruWeb;

    public:
        WifiConfig();
        void Tick();
};