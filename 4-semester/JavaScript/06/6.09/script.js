allAnswers = ["Evangelion", "Naruto: Shippuuden", "Berserk", "Attack on Titan", "Chainsaw Man"]
correctOrderedAnswers = ["Chainsaw Man", "Berserk", "Attack on Titan", "Naruto: Shippuuden", "Evangelion"]

function check()
{
    let forms = document.getElementsByName("list")
    // console.log(forms)
    let cnt = 0
    for (let j = 0; j < forms.length; j++)
    {
        let select = forms[j]
        for (let i = 0; i < select.length; i++)
        {
            if (select[i].selected)
            {
                // console.log(allAnswers[i], correctOrderedAnswers[j])
                if (allAnswers[i] == correctOrderedAnswers[j])
                {
                    cnt += 1
                }
            }
        }
    }
    let out = document.getElementById("output")
    out.textContent = `Correct Answers: ${cnt}`
}

function change()
{
    let out = document.getElementById("output")
    out.textContent = ""
}