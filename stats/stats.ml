(* Helper functions *)
let mean lst =
  let sum = List.fold_left (+) 0 lst in
  float_of_int sum /. float_of_int (List.length lst)

let median lst =
  let sorted = List.sort compare lst in
  let n = List.length sorted in
  if n mod 2 = 0 then
    let a = List.nth sorted (n/2 - 1)
    and b = List.nth sorted (n/2) in
    (float_of_int (a + b)) /. 2.0
  else
    float_of_int (List.nth sorted (n/2))

let mode lst =
  let rec count x lst = List.fold_left (fun acc y -> if y = x then acc + 1 else acc) 0 lst in
  let unique = List.sort_uniq compare lst in
  let max_count = List.fold_left (fun acc x -> max acc (count x lst)) 0 unique in
  List.filter (fun x -> count x lst = max_count) unique

(* Main program *)
let () =
  print_endline "Enter integers separated by spaces:";
  let input = read_line () in
  let nums = List.map int_of_string (String.split_on_char ' ' input) in
  Printf.printf "Mean: %.2f\n" (mean nums);
  Printf.printf "Median: %.2f\n" (median nums);
  print_string "Mode(s): ";
  List.iter (fun x -> Printf.printf "%d " x) (mode nums);
  print_newline ()
