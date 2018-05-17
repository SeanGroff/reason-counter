[%bs.raw {|require('./Counter.css')|}];

type state = {
  count: int,
};

type action =
  | Increment
  | Decrement;

let component = ReasonReact.reducerComponent("Counter");

let make = _children => {
  ...component,

  initialState: () => {count: 0},

  reducer: (action, state) =>
    switch (action) {
    | Increment => ReasonReact.Update({count: state.count + 1})
    | Decrement => ReasonReact.Update({
      count: state.count == 0 ? state.count : state.count - 1
    })
    },

  render: self => {
    <div className="counter">
      <header className="counter--header">
        <h1>{ReasonReact.string("ReasonReact")}</h1>
        <h3>{ReasonReact.string("Counter")}</h3>
      </header>
      <div className="counter--actions">
        <div className="counter--count">
          {ReasonReact.string(string_of_int(self.state.count))}
        </div>
        <div className="counter--buttons">
          <button
            className="counter--btn counter--btn-dec"
            disabled={self.state.count === 0}
            onClick={_event => self.send(Decrement)}>
            {ReasonReact.string("-")}
          </button>
          <button
            className="counter--btn counter--btn-inc"
            onClick={_event => self.send(Increment)}>
              {ReasonReact.string("+")}
          </button>
        </div>
      </div>
    </div>
  }
};
