#include "./WifiConfig/WifiConfig.h" 
char mqttServeur[40];
WiFiManagerParameter m_parametrePersonalise("Serveur","mqttServeur",mqttServeur,40);

WifiConfig::WifiConfig()
{ 
    this->m_wifiManager.erase();
    this->m_adresseIPPortail = new IPAddress(192,168,23,1);
    this->m_passerellePortail = new IPAddress(192,168,23,1);
    this->m_masqueReseauPortail = new IPAddress(255,255,255,0);
    
    this->m_wifiManager.setDebugOutput(false);
    this->m_wifiManager.setAPCallback([](WiFiManager* p_wiFiManager){
        Serial.println("Connexion au reseau WiFi echouee, on lance le portail !");
    });
    this->m_wifiManager.setConfigPortalTimeout(600);

    this->m_wifiManager.addParameter(&m_parametrePersonalise);

    this->m_wifiManager.setAPStaticIPConfig(*this->m_adresseIPPortail,*this->m_passerellePortail,*this->m_masqueReseauPortail);

    this->m_wifiManager.setParamsPage(true);

    this->m_wifiManager.autoConnect(this->SSIDProtail, this->motPasseAPortail);

    this->m_serveurWeb.on(UriRegex("/.*"), []() {
        //m_serveruWeb.send(200,"text/plain","Bienvenue sur mon site web!");
    });
    if(WiFi.isConnected()){
        this->m_serveurWeb.begin();
        Serial.println("Connecté au réseau : " + WiFi.SSID() +
                   " avec l'adresse : " + WiFi.localIP().toString());
    }
    this->m_addresseMqtt = strcpy(mqttServeur, m_parametrePersonalise.getValue());
}

IPAddress* WifiConfig::GetAddresseMQTT()
{
    uint8_t ip[4];
    IPAddress* addresseRetourner;
    sscanf(m_addresseMqtt, "%u.%u.%u.%u", &ip[0],&ip[1],&ip[2],&ip[3]);
    addresseRetourner = new IPAddress(ip);
    return addresseRetourner;
}