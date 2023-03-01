/*
 * button.c
 *
 *  Created on: 15.02.2015
 *      Author: Florian
 */


/*---------------------------------------------------------------------*
 *  include files                                                      *
 *---------------------------------------------------------------------*/
#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#include "button.h"
/*---------------------------------------------------------------------*
 *  local definitions                                                  *
 *---------------------------------------------------------------------*/
#define USER_KEY_BTN GET_PIN(H, 4)
/*---------------------------------------------------------------------*
 *  external declarations                                              *
 *---------------------------------------------------------------------*/

/*---------------------------------------------------------------------*
 *  public data                                                        *
 *---------------------------------------------------------------------*/

/*---------------------------------------------------------------------*
 *  private data                                                       *
 *---------------------------------------------------------------------*/

/*---------------------------------------------------------------------*
 *  private functions                                                  *
 *---------------------------------------------------------------------*/

/*---------------------------------------------------------------------*
 *  public functions                                                   *
 *---------------------------------------------------------------------*/

int button_init (void)
{
    rt_pin_mode(USER_KEY_BTN, PIN_MODE_INPUT_PULLUP);
    return RT_EOK;
}
INIT_APP_EXPORT(button_init);

rt_bool_t button_read (void)
{
    return rt_pin_read(USER_KEY_BTN) > 0 ? PIN_HIGH : PIN_LOW;
}

/*---------------------------------------------------------------------*
 *  eof                                                                *
 *---------------------------------------------------------------------*/
