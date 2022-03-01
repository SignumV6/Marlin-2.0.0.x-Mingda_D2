#include "../TSC_Menu.h"


#include "../../../../../feature/bltouch.h"

const MENUITEMS autoLevelingItems = {
// title
LABEL_LEVELING,
// icon                        label
 {
  #if ENABLED(AUTO_BED_LEVELING_BILINEAR)
    {ICON_LEVELING,              LABEL_ABL},
  #else 
    {ICON_LEVELING,              LABEL_UBL},
  #endif
    {ICON_BLTOUCH,               LABEL_BLTOUCH},
    {ICON_TRAMMING,              LABEL_TRAMMING},
    {ICON_MBL,                   LABEL_MBL},
    {ICON_PROBE_OFFSET,          LABEL_PROBE_OFFSET},
    {ICON_BABYSTEP,              LABEL_BABYSTEP},
    {ICON_EM_STOP,               LABEL_EMERGENCYSTOP},
    {ICON_BACK,                  LABEL_BACK},
  }
};

void menuCallBackAutoBedLeveling(void)
{
  KEY_VALUES key_num = menuKeyGetValue();
  switch(key_num)
  {
    case KEY_ICON_0:
      #if ENABLED(AUTO_BED_LEVELING_BILINEAR)
      storeCmd("G28");
      storeCmd("G29");
      storeCmd("M500");
      #else 
        // UBL
        infoMenu.menu[++infoMenu.cur] = menuUBL;
      #endif
      break;
    case KEY_ICON_1:
      infoMenu.menu[++infoMenu.cur] = menubltouch;
      break;
    case KEY_ICON_2:
      infoMenu.menu[++infoMenu.cur] = menuTramming;
      break; 
    case KEY_ICON_3:
      infoMenu.menu[++infoMenu.cur] = menuManualLeveling;
      break;
    case KEY_ICON_4:
      infoMenu.menu[++infoMenu.cur] = menuProbeOffset;
      break;
    case KEY_ICON_5:
      infoMenu.menu[++infoMenu.cur] = menuBabyStep;
      break;
    case KEY_ICON_6:
      flashFirmware(1);
      break;
    case KEY_ICON_7:
      infoMenu.cur--; break;
    default:break;
  }
}

void menuAutoLeveling()
{
  menuDrawPage(&autoLevelingItems);
  menuSetFrontCallBack(menuCallBackAutoBedLeveling);
}

