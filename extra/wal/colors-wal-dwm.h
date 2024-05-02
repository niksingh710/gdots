static const char norm_fg[] = "#c5c5c5";
static const char norm_bg[] = "#191919";
static const char norm_border[] = "#525252";

static const char sel_fg[] = "#c5c5c5";
static const char sel_bg[] = "#582c1e";
static const char sel_border[] = "#c5c5c5";

static const char urg_fg[] = "#c5c5c5";
static const char urg_bg[] = "#3a3632";
static const char urg_border[] = "#3a3632";

static const char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
    [SchemeUrg] =  { urg_fg,      urg_bg,    urg_border },
};
