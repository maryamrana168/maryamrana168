def Counter(matches):
    for victory in matches:
        wins=0
        wins+=1

def sports_tournament_stats(teams, matches):
     
    wins = Counter(matches)
    total_scores = 0
    for t1, t2, s1, s2 in matches:
        total_scores += (s1 + s2)
        if s1 > s2:
            wins[t1] += 1
        elif s2 > s1:
            wins[t2] += 1
        else:
            # tie - count half-win optionally
            pass
    winner = wins.most_common(1)[0] if wins else (None, 0)
    average_score = total_scores / len(matches) if matches else 0
    participants = set()
    for m in matches:
        participants.add(m[0]); participants.add(m[1])
    return winner, average_score, participants


def task9_demo():
    teams = {"A", "B", "C", "D"}
    matches = [
        ("A","B",2,1),
        ("C","D",1,1),
        ("A","C",3,0),
        ("B","D",0,2),
    ]
    print("Task 9 — Sports Tournament Statistics")
    winner, avg_score, participants = sports_tournament_stats(teams, matches)
    print("Winning team (most wins):", winner)
    print("Average score per match:", avg_score)
    print("Participants:", participants)
task9_demo()