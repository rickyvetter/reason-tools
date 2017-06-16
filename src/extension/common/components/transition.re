
type state = {
  style: ReactDOMRe.Style.t
};
 
let component = ReasonReact.statefulComponent "Transition";
let make ::before ::after children => {
  ...component,

  initialState: fun () => {
    style: before
  },

  didMount: fun _ self => {
    Core.Util.setTimeout (self.update (fun _ _ _ => ReasonReact.Update {style: after})) 0;
    ReasonReact.NoUpdate
  },

  render: fun state _ =>
    <div style=state.style> (ReasonReact.arrayToElement children) </div>
};