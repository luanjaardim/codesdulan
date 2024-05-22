(* round_dfrac is used to round x value to d decimals *)
let round_dfrac d x =
  if x -. (Float.round x) = 0. then x else  (* x is an integer. *)
  let m = 10. ** (float d) in               (* m moves 10^-d to 1. *)
  (floor ((x *. m) +. 0.5)) /. m 
;;
