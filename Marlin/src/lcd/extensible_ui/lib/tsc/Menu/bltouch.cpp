#include "../TSC_Menu.h"


//#include "../../../../../feature/bltouch.h"

const MENUITEMS BltouchItems = {
// title
LABEL_ABL,
// icon                        label
 {{ICON_BLTOUCH_DEPLOY,        LABEL_BLTOUCH_DEPLOY},
  {ICON_BLTOUCH_STOW,          LABEL_BLTOUCH_STOW},
  {ICON_BLTOUCH_TEST,          LABEL_BLTOUCH_TEST},
  {ICON_BLTOUCH_INIT,          LABEL_BLTOUCH_INIT},
  {ICON_PROBE_OFFSET,          LABEL_PROBE_OFFSET},
  {ICON_BACKGROUND,            LABEL_BACKGROUND},
  {ICON_BACKGROUND,            LABEL_BACKGROUND},
  {ICON_BACK,                  LABEL_BACK},}
};

void menuCallBackbltouch(void)
{
  KEY_VALUES key_num = menuKeyGetValue();
  switch(key_num)
  {
    case KEY_ICON_0:
      storeCmd("M280 P0 S10\n");
      break;
    case KEY_ICON_1:
      storeCmd("M280 P0 S90\n");
      break;
    case KEY_ICON_2:
      storeCmd("M280 P0 S120\n");
      break;
    case KEY_ICON_3:
      storeCmd("M280 P0 S160\n");
      break;
    case KEY_ICON_4:
      infoMenu.menu[++infoMenu.cur] = menuProbeOffset;
      break;
    case KEY_ICON_7:
      infoMenu.cur--; break;
    default:break;
  }
}

void menubltouch()
{
  menuDrawPage(&BltouchItems);
  menuSetFrontCallBack(menuCallBackbltouch);
}


