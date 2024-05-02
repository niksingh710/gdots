const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#191919", /* black   */
  [1] = "#3a3632", /* red     */
  [2] = "#582c1e", /* green   */
  [3] = "#423f39", /* yellow  */
  [4] = "#50473c", /* blue    */
  [5] = "#634723", /* magenta */
  [6] = "#5a5149", /* cyan    */
  [7] = "#8c8c8c", /* white   */

  /* 8 bright colors */
  [8]  = "#525252",  /* black   */
  [9]  = "#4e4843",  /* red     */
  [10] = "#763b28", /* green   */
  [11] = "#59554c", /* yellow  */
  [12] = "#6b5f51", /* blue    */
  [13] = "#855f2f", /* magenta */
  [14] = "#796d62", /* cyan    */
  [15] = "#c5c5c5", /* white   */

  /* special colors */
  [256] = "#191919", /* background */
  [257] = "#c5c5c5", /* foreground */
  [258] = "#c5c5c5",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 257;
 unsigned int defaultcs = 258;
 unsigned int defaultrcs= 258;
