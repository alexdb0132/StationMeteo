#include "./WifiConfig/WifiConfig.h"

WifiConfig::WifiConfig()
{
    this->m_wifiManager.erase();
    this->m_adresseIPPortail = new IPAddress(192,168,23,1);
    this->m_passerellePortail = new IPAddress(192,168,23,1);
    this->m_masqueReseauPortail = new IPAddress(25,255,255,0);
    this->m_parametrePersonalise = new WiFiManagerParameter("bateau super cool","bateau","modele bleu",40);
    
    this->m_wifiManager.setDebugOutput(false);
    this->m_wifiManager.setAPCallback([](WiFiManager* p_wiFiManager){
        Serial.println("Connexion au reseau WiFi echouee, on lance le portail !");
    });
    this->m_wifiManager.setConfigPortalTimeout(200);

    this->m_wifiManager.addParameter(m_parametrePersonalise);

    this->m_wifiManager.setAPStaticIPConfig(*this->m_adresseIPPortail,*this->m_passerellePortail,*this->m_masqueReseauPortail);

    this->m_wifiManager.setParamsPage(true);

    this->m_wifiManager.autoConnect(this->SSIDProtail, this->motPasseAPortail);
    this->m_serveruWeb.on(UriRegex("/.*"), []() {
        //m_serveruWeb.send(200,"text/plain","Bienvenue sur mon site web!");
    });
    if(WiFi.isConnected()){
        this->m_serveruWeb.begin();
        Serial.println("Connecté au réseau : " + WiFi.SSID() +
                   " avec l'adresse : " + WiFi.localIP().toString());
    }
}
void WifiConfig::Tick()
{
    if(WiFi.isConnected()){
        this->m_serveruWeb.handleClient();
    }
}