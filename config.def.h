/* See LICENSE file for copyright and license details. */

/* appearance */
#define NUMCOLORS 7
static const unsigned long colors[] = {
    0x54ebff,   // \x01
    0xdb6794,   // \x02
    0xef9c3a,   // \x03
    0xa4bc74,   // \x04
    0x99FF99,   // Good \x05
    0xFF6600,   // Warning \x06
    0xC63333,   // Caution \x07
};
static const char font[]            = "-*-stlarch-medium-r-*-*-10-*-*-*-*-*-*-*" "," "-*-ohsnap.icons-medium-r-normal-*-11-*-*-*-*-*-*-*";
static const char normbordercolor[] = "#EB6C02";//"#002C91";
static const char normbgcolor[]     = "#222222";
static const char normfgcolor[]     = "#EB6C02";
static const char selbordercolor[]  = "#1A5FFF";
static const char selbgcolor[]      = "#EB6C02";
static const char selfgcolor[]      = "#222222";
static const char floatnormbordercolor[] = "#EB6C02";//"#885599";
static const char floatselbordercolor[]  = "#52f799";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const Bool systraypinningfailfirst = True;   /* True: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const Bool showsystray       = True;     /* False means no systray */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = False;     /* False means bottom bar */

/* tagging */
static const char *tags[] = { "Dev", "Web", "Trm", "Thu", "5", "6", "Snd", "8", "Dwn" };

static const Rule rules[] = {
  /* xprop(1):
   *  WM_CLASS(STRING) = instance, class
   *  WM_NAME(STRING) = title
   */
  /* class                instance    title       tags mask     isfloating   monitor */
    { "Gimp",               NULL,       NULL,       0,            True,        -1},
    { "Eclipse",            NULL,       NULL,       1 << 0,       False,       -1},
    { "Chromium-browser",   NULL,       NULL,       1 << 1,       False,       -1},
    { "Firefox",            NULL,       NULL,       1 << 1,       False,       -1},
    { "X-terminal-emulator",NULL,       NULL,       1 << 2,       False,       -1},
    { "Thunar",             NULL,       NULL,       1 << 3,       False,       -1},
    { "mplayer2",           NULL,       NULL,       1 << 6,       False,       -1},
    { "Parole",             NULL,       NULL,       1 << 6,       False,       -1},
    { "Transmission-gtk",   NULL,       NULL,       1 << 8,       False,       -1},
};

/* layout(s) */
static const float mfact      = 0.65; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */

#include "gaplessgrid.c"
static const Layout layouts[] = {
  /* symbol     arrange function */
  { "[]=",      tile },    /* first entry is default */
  { "><>",      NULL },    /* no layout function means floating behavior */
  { "[M]",      monocle },
  { "+++",      gaplessgrid },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
  { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
  { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "x-terminal-emulator", NULL };
static const char *chgwall[]  = { "/home/hkr/Drive/bin/wall_aleatorio.sh", NULL};
static const char *idecmd[]   = { "/home/hkr/Desarrollo/eclipse/eclipse", NULL};
static const char *printcmd[] = { "xfce4-screenshooter", NULL};
static const char *foxcmd[]   = { "firefox", NULL};
static const char *chrocmd[]  = { "chromium-browser", NULL};
static const char *thunarcmd[]= { "nemo --no-desktop", NULL};
//static const char *upvol[] = { "amixer", "set", "Master", "3+", NULL};
//static const char *downvol[] = { "amixer", "set", "Master", "3-", NULL};
//static const char *mutevol[] = { "amixer", "set", "Master", "toggle", NULL};


#include "toggleview_focus.c"
#include "moveresize.c"
#include "tagall.c"
#include "maximize.c"
#include "zoomswap.c"
#include "push.c"
#include "focusmaster.c"
#include "shifttags.c"
#include "keepfloatingposition.c"
static Key keys[] = {
  /* modifier                     key        function        argument */
  { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
  { MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
  { MODKEY,                       XK_s,      spawn,          {.v = chgwall} },
  { MODKEY,                       XK_e,      spawn,          {.v = idecmd} },
  { MODKEY|ShiftMask,             XK_f,      spawn,          {.v = foxcmd} },
  { MODKEY|ShiftMask,             XK_i,      spawn,          {.v = chrocmd} },
  { 0,                            XK_Print,  spawn,          {.v = printcmd} },
  { MODKEY|ShiftMask,             XK_t,      spawn,          {.v = thunarcmd} },
//  { 0,                            0x1008ff12,spawn,          {.v = mutevol} },
//  { 0,                            0x1008ff11,spawn,          {.v = downvol} },
//  { 0,                            0x1008ff13,spawn,          {.v = upvol} },
  { MODKEY,                       XK_b,      togglebar,      {0} },
  { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
  { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
  { MODKEY|ShiftMask,             XK_j,      pushdown,       {0} },
  { MODKEY|ShiftMask,             XK_k,      pushup,         {0} },
  { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
  { MODKEY,                       XK_o,      incnmaster,     {.i = -1 } },
  { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
  { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
  { MODKEY,                       XK_Return, zoom,           {0} },
  { Mod1Mask,                     XK_Tab,    swapfocus,      {0} },
  { MODKEY,                       XK_Tab,    view,           {0} },
  { MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
  { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
  { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
  { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
  { MODKEY,                       XK_g,      setlayout,      {.v = &layouts[3]} },
  { MODKEY,                       XK_space,  toggleview_focus, {.ui = 1} },
  { MODKEY|ControlMask,           XK_space,  setlayout,      {0} },
  { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
  { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
  { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
  { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
  { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
  { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
  { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
  TAGKEYS(                        XK_1,                      0)
  TAGKEYS(                        XK_2,                      1)
  TAGKEYS(                        XK_3,                      2)
  TAGKEYS(                        XK_4,                      3)
  TAGKEYS(                        XK_5,                      4)
  TAGKEYS(                        XK_6,                      5)
  TAGKEYS(                        XK_7,                      6)
  TAGKEYS(                        XK_8,                      7)
  TAGKEYS(                        XK_9,                      8)
  { MODKEY,                       XK_q,      quit,           {1} },
  { MODKEY|ShiftMask,             XK_q,      quit,           {0} },
  { MODKEY|ControlMask,           XK_l,      togglehorizontalmax, {0} },
  { MODKEY|ControlMask,           XK_h,      togglehorizontalmax, {0} },
  { MODKEY|ControlMask,           XK_j,      toggleverticalmax,   {0} },
  { MODKEY|ControlMask,           XK_k,      toggleverticalmax,   {0} },
  { MODKEY|ControlMask,           XK_m,      togglemaximize,      {0} },
  { MODKEY|ShiftMask,             XK_F1,     tagall,         {.v = "F1" } },
  { MODKEY|ShiftMask,             XK_F2,     tagall,         {.v = "F2" } },
  { MODKEY|ShiftMask,             XK_F3,     tagall,         {.v = "F3" } },
  { MODKEY|ShiftMask,             XK_F4,     tagall,         {.v = "F4" } },
  { MODKEY|ShiftMask,             XK_F5,     tagall,         {.v = "F5" } },
  { MODKEY|ShiftMask,             XK_F6,     tagall,         {.v = "F6" } },
  { MODKEY|ShiftMask,             XK_F7,     tagall,         {.v = "F7" } },
  { MODKEY|ShiftMask,             XK_F8,     tagall,         {.v = "F8" } },
  { MODKEY|ShiftMask,             XK_F9,     tagall,         {.v = "F9" } },
  { MODKEY,                       XK_a,      moveresize,     {.v = "-10x 0y 0w 0h" } },
  { MODKEY,                       XK_d,      moveresize,     {.v = "10x 0y 0w 0h" } },
  { MODKEY,                       XK_s,      moveresize,     {.v = "0x 10y 0w 0h" } },
  { MODKEY,                       XK_w,      moveresize,     {.v = "0x -10y 0w 0h" } },
  { MODKEY|ControlMask,           XK_a,      moveresize,     {.v = "0X 0y 0w 0h" } },
  { MODKEY|ControlMask,           XK_d,      moveresize,     {.v = "9000X 0y 0w 0h" } },
  { MODKEY|ControlMask,           XK_s,      moveresize,     {.v = "0x 9000Y 0w 0h" } },
  { MODKEY|ControlMask,           XK_w,      moveresize,     {.v = "0x 15Y 0w 0h" } },
  { MODKEY|ShiftMask,             XK_a,      moveresize,     {.v = "0x 0y -10w 0h" } },
  { MODKEY|ShiftMask,             XK_d,      moveresize,     {.v = "0x 0y 10w 0h" } },
  { MODKEY|ShiftMask,             XK_s,      moveresize,     {.v = "0x 0y 0w 10h" } },
  { MODKEY|ShiftMask,             XK_w,      moveresize,     {.v = "0x 0y 0w -10h" } },
  { MODKEY|ControlMask,           XK_Return, focusmaster,    {0} },
  { MODKEY,                       XK_Left,   shifttags,      {.i = -1} },
  { MODKEY,                       XK_Right,  shifttags,      {.i = +1} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
  /* click                event mask      button          function        argument */
  { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
  { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
  { ClkWinTitle,          0,              Button2,        zoom,           {0} },
  { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
  { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
  { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
  { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
  { ClkTagBar,            0,              Button1,        view,           {0} },
  { ClkTagBar,            0,              Button3,        toggleview,     {0} },
  { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
  { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
