# Day 3 人在做，天在看

前几天研究大佬的历史，看见一个PR之后管理员Revert了好几次，我心想这是什么操作？结果昨天自己上演了一次Revert好戏。

昨天Git Commit了一个语法不正确的Markdown文本，是README级别的Markdown。
Commit了还不要紧，发现之后我想删除Commit，忘记了有Git Ammend可以用，直接上去就是一记Revert。

Revert还不要紧，关键是我还Push了。

Push还不要紧，关键是我还设置了Branch Protection，这样一来Git历史就会变得无比脏。

最后进入sudo模式，将Branch Protection临时关闭了之后才一波强推解决问题。

人在做，天在看。这次在大佬面前丢足了脸。记住这次教训，Git不要随便推送，遇到问题不要Revert，要Ammend。
如果提交了两次推送也不要紧，Reset Mixed大不了就是Reset Hard。要是到最后需要Force Push就悲催丢大脸了。

# Ritual Books

- [ ] 知识
- [ ] 历史
- [ ] 技能
- [ ] 语文
- [ ] 数学
- [ ] 书法
