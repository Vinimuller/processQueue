#include "../inc/classes/OrquestradorCenas.h"

OrquestradorCenas::OrquestradorCenas(Personagem *heroi){
    this->heroi = heroi;
}

string OrquestradorCenas::getUltimaCena(){
    return ultimaCena;
}

void OrquestradorCenas::setUltimaCena(string ultimaCena){
    this->ultimaCena = ultimaCena;
}

void OrquestradorCenas::runCena(){
    
}