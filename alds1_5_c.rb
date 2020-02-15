th = Math::PI * 60 / 180
@cos60 = 0.5
@sin60 = Math.sin(th)

class Point
  def initialize(x:, y:)
    @x = x.to_r
    @y = y.to_r
  end

  def to_s
    "#{x.to_f} #{y.to_f}"
  end

  attr_reader :x, :y
end

def koch(d, a, b)
  return if d == 0

  s = Point.new(
    x: (2 * a.x + 1 * b.x) / 3,
    y: (2 * a.y + 1 * b.y) / 3
  )
  t = Point.new(
    x: (1 * a.x + 2 * b.x) / 3,
    y: (1 * a.y + 2 * b.y) / 3
  )
  u = Point.new(
    x: (t.x - s.x) * @cos60 - (t.y - s.y) * @sin60 + s.x,
    y: (t.x - s.x) * @sin60 + (t.y - s.y) * @cos60 + s.y
  )

  koch(d - 1, a, s)
  puts s

  koch(d - 1, s, u)
  puts u

  koch(d - 1, u, t)
  puts t

  koch(d - 1, t, b)
end

n = gets.chomp.to_i
p1 = Point.new(x: 0, y: 0)
p2 = Point.new(x: 100, y: 0)

puts p1
koch(n, p1, p2)
puts p2