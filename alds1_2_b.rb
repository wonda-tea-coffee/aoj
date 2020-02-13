n = gets.chomp.to_i
a = gets.chomp.split.map(&:to_i)

cnt = 0
0.upto(n - 1) do |i|
  minj = i

  (i + 1).upto(n - 1) do |j|
    if a[j] < a[minj]
      minj = j
    end
  end

  if i != minj
    tmp = a[i]
    a[i] = a[minj]
    a[minj] = tmp

    cnt += 1
  end
end
puts a.map(&:to_s).join(' ')
puts cnt