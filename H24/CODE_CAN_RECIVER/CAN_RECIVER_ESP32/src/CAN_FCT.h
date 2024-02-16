/*
Programme : main.cpp
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      12 février 2024
Brief :     

Matérielle:  
Encironement:
*/



#include <ESP32-TWAI-CAN.hpp>
#include "ID_CAPT.h"
#include <math.h>






/*
Brief   : Affiche le premier octet de la section "data" de la trame CAN.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void affiche_data(CanFrame rxFrame)
{
    Serial.printf("%c \n", rxFrame.data[0]);
}


/*
Brief   : Vérifie si le premier octet, de la section "data" de la trame CAN,
          est bien un nombre. Si oui, on l'affiche. Sinon, on affiche un 
          message d'erreur.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void verif_trame(CanFrame rxFrame)
{
  if(!(isnan(rxFrame.data[0])))
    affiche_data(rxFrame);
  else
    Serial.printf("ERREUR!!!!!!!!!!!!!!");
}


/*
Brief   : Affiche la Température du liquide de refroidissement.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void coolant_temp(CanFrame rxFrame)
{
  Serial.printf("Température du liquide de refroidissement : ");
  verif_trame(rxFrame);
}

/*
Brief   : Affiche la Température interne de l’onduleur.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void drive_temp(CanFrame rxFrame)
{
  Serial.printf("Température interne de l’onduleur : ");
  verif_trame(rxFrame);
}



/*
Brief   : Affiche la Température interne du moteur.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void motor_temp(CanFrame rxFrame)
{
  Serial.printf("Température interne du moteur : ");
  verif_trame(rxFrame);
}

/*
Brief   : Affiche la Température interne de l’accumulateur.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void hv_temp(CanFrame rxFrame)
{
  Serial.printf("Température interne de l’accumulateur : ");
  verif_trame(rxFrame);
}

/*
Brief   : Affiche le Niveau de charge de l’accumulateur.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void hv_soc(CanFrame rxFrame)
{
  Serial.printf("Niveau de charge de l’accumulateur : ");
  verif_trame(rxFrame);
}


/*
Brief   : Affiche le Niveau de santé de l’accumulateur.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void hv_soh(CanFrame rxFrame)
{
  Serial.printf("Niveau de santé de l’accumulateur : ");
  verif_trame(rxFrame);
}

/*
Brief   : Affiche la Tension totale de l’accumulateur.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void hv_voltage(CanFrame rxFrame)
{
  Serial.printf("Tension totale de l’accumulateur : ");
  verif_trame(rxFrame);
}

/*
Brief   : Affiche le Niveau de charge de la batterie 12V.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void lv_soc(CanFrame rxFrame)
{
  Serial.printf("Niveau de charge de la batterie 12V : ");
  verif_trame(rxFrame);
}


/*
Brief   : Affiche la Tension de la batterie 12V.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void lv_voltage(CanFrame rxFrame)
{
  Serial.printf("Tension de la batterie 12V : ");
  verif_trame(rxFrame);
}

/*
Brief   : Affiche la Température de la batterie 12V.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void lv_temp(CanFrame rxFrame)
{
  Serial.printf("Température de la batterie 12V : ");
  verif_trame(rxFrame);
}



/*
Brief   : Lis le port série à chaque seconde. Si une trame CAN
          est reçus, on regarde l'ID et on appel la fonction
          d'affichage correspondante.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void read_CAN(CanFrame rxFrame)
{
    // Si on reçois une transmission, on regarde le ID puis,
    // on affiche le bon message.
    if(ESP32Can.readFrame(rxFrame, 1000))
    {
        
        
      switch (rxFrame.identifier)
      {
      case COOLANT_TEMP:
        coolant_temp(rxFrame);
        break;
      case DRIVE_TEMP:
        drive_temp(rxFrame);
        break;
      case MOTOR_TEMP:
        motor_temp(rxFrame);
        break;
      case HV_TEMP:
        hv_temp(rxFrame);
        break;
      case HV_SOC:
        hv_soc(rxFrame);
        break;
      case HV_SOH:
        hv_soc(rxFrame);
        break;
      case HV_VOLTAGE:
        hv_voltage(rxFrame);
        break;
      case LV_SOC:
        lv_soc(rxFrame);
        break;
      case LV_VOLTAGE:
        lv_voltage(rxFrame);
        break;
      case LV_TEMP:
        lv_temp(rxFrame);
        break;
      default:
        break;
      }
              
    }
}