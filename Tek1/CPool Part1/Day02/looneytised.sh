#!/bin/bash
sed "s/theo1/Wile E. Coyote/gi" | sed "s/steven1/Daffy Duck/gi" | sed "s/arnaud1/Porky Pig/gi" | sed "s/pierre-jean/Marvin the Martian/gi" | grep -E "Wile E. Coyote|Daffy Duck|Porky Pig|Marvin the Martian"
