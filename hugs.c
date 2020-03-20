/*******************************************************************
 *
 * $Id: beeps.c,v 1.10 2000/06/05 04:13:34 const Exp $
 * Beeping functionality.
 *
 * Copyright (c) Const Kaplinsky <const@ce.cctpu.edu.ru>, 2000.
 *
 * Original "Telechat" is copyrighted by Hyperreal, 1996.
 * For more information consult the file LICENSE.
 *
 *******************************************************************/

#include "telechat.h"

static void cmd_hug2 (SLOT *dst_slot, char *id);

void cmd_hug (void)
{
  writestr (cur_slot, "Hug: ");
  setproc_id (cmd_hug2, PROC_ID_ONLINE);
}

static void cmd_hug2 (SLOT *dst_slot, char *id)
{
  if (!squelched (dst_slot, cur_slot) && !reversed (cur_slot, dst_slot)) {
    sprintf (msg_buf, " * You are being *hugged* by %s/%s",
             cur_slot->acct.id, cur_slot->acct.handle);
    writeaction (dst_slot, msg_buf);
  }
  writestr (cur_slot, "Hug sent.\n");
  setproc (sendpub, MAXMSG, 0);
}

