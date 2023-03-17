import System.Process (readProcessWithExitCode)
import GHC.Data.ShortText (ShortText(contents))
import Text.XHtml (rows)
-- Convert a CSV file to an HTML table

input = "Germany,Nico Schlotterbeck,Defender,,190 lbs,6' 3\",22,12/1/1999,,,Germany,Borussia Dortmund,German Bundesliga\n\
\Germany,Christian Günter,Defender,,183 lbs,6' 0\",29,2/28/1993,,,Germany,SC Freiburg,German Bundesliga\n\
\Germany,Armel Bella Kotchap,Defender,,192 lbs,6' 3\",20,12/11/2001,,,Germany,Southampton,English Premier League\n\
\Germany,Antonio Rüdiger,Defender,,185 lbs,6' 3\",29,3/3/1993,,,Germany,Real Madrid,Spanish LaLiga"

open tag = '<':tag ++ ['>']

close tag = '<':'/':tag ++ ['>']

tagify tag txt = open tag ++ txt ++ close tag

makeRow x = tagify "tr" rowText
    where rowText = concatMap (tagify "td") x

makeTable x = tagify "table" contents
    where contents = concatMap makeRow rows
          rows = map (splitOn ",") (lines x)
          